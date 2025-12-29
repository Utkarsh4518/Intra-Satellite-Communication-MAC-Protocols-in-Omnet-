#include "LifiApp.h"

Define_Module(LifiApp);

void LifiApp::initialize()
{
    meanInterArrival = par("meanInterArrival").doubleValue();
    packetLength = par("packetLength").intValue();

    // statistics
    numGenerated = 0;
    numGeneratedSignal = registerSignal("numGenerated");

    sendTimer = new cMessage("sendTimer");
    scheduleAt(simTime() + exponential(meanInterArrival), sendTimer);
}

void LifiApp::handleMessage(cMessage *msg)
{
    if (msg == sendTimer) {
        char pkName[32];
        sprintf(pkName, "pkt-%ld", getEnvir()->getUniqueNumber());
        auto *pkt = new cPacket(pkName);
        pkt->setByteLength(packetLength);

        // count generated packet
        numGenerated++;
        emit(numGeneratedSignal, 1);

        send(pkt, "out");
        scheduleAt(simTime() + exponential(meanInterArrival), sendTimer);
    }
    else {
        delete msg;
    }
}

void LifiApp::finish()
{
    cancelAndDelete(sendTimer);
    sendTimer = nullptr;

    recordScalar("numGenerated", numGenerated);
}
