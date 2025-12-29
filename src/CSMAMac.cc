#include "CSMAMac.h"

Define_Module(CSMAMac);

void CSMAMac::initialize()
{
    meanBackoff = par("meanBackoff").doubleValue();

    // statistics
    numFromUpper = 0;
    numSent = 0;
    numFromUpperSignal = registerSignal("numFromUpper");
    numSentSignal = registerSignal("numSent");

    backoffTimer = new cMessage("backoffTimer");
}

void CSMAMac::handleMessage(cMessage *msg)
{
    if (msg == backoffTimer)
        handleBackoffTimer();
    else if (msg->arrivedOn("lowerIn"))
        handleFromLower(msg);
    else
        handleFromUpper(msg);
}


void CSMAMac::handleFromUpper(cMessage *msg)
{
    numFromUpper++;
    emit(numFromUpperSignal, 1);

    txQueue.insert(msg);
    tryTransmit();
}

void CSMAMac::handleBackoffTimer()
{
    // no-op in simplified version
}

void CSMAMac::handleFromLower(cMessage *msg)
{
    // for now, just consume the frame
    delete msg;
}


void CSMAMac::tryTransmit()
{
    if (txQueue.isEmpty())
        return;

    cMessage *pkt = (cMessage *)txQueue.pop();

    EV_INFO << "CSMA sending packet " << pkt->getName()
            << " at t=" << simTime() << endl;

    numSent++;
    emit(numSentSignal, 1);

    send(pkt, "lowerOut");
}



void CSMAMac::finish()
{
    cancelAndDelete(backoffTimer);
    backoffTimer = nullptr;

    while (!txQueue.isEmpty()) {
        delete txQueue.pop();
    }

    recordScalar("numFromUpper", numFromUpper);
    recordScalar("numSent", numSent);
}

