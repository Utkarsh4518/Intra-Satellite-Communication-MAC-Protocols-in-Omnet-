#include "AlohaMac.h"

Define_Module(AlohaMac);

void AlohaMac::initialize()
{
    meanRetransmit = par("meanRetransmit").doubleValue();

    // statistics
    numFromUpper = 0;
    numSent = 0;
    numCollisions = 0;
    numDropped = 0;
    numFromUpperSignal = registerSignal("numFromUpper");
    numSentSignal = registerSignal("numSent");
    numCollisionsSignal = registerSignal("numCollisions");
    numDroppedSignal = registerSignal("numDropped");

    retransmitTimer = new cMessage("retransmitTimer");
}

void AlohaMac::handleMessage(cMessage *msg)
{
    if (msg == retransmitTimer) {
        handleRetransmitTimer();
    }
    else {
        // from upper layer
        handleFromUpper(msg);
    }
}

void AlohaMac::handleFromUpper(cMessage *msg)
{
    numFromUpper++;
    emit(numFromUpperSignal, 1);

    txQueue.insert(msg);
    tryTransmit();
}

void AlohaMac::handleRetransmitTimer()
{
    transmitting = false;
    tryTransmit();
}

void AlohaMac::tryTransmit()
{
    if (transmitting || txQueue.isEmpty())
        return;

    // Pure ALOHA: send immediately
    cMessage *pkt = (cMessage *)txQueue.pop();

    numSent++;
    emit(numSentSignal, 1);

    send(pkt, "lowerOut");
    transmitting = true;

    // Simplified: pretend some packets collide and need retransmission
    if (uniform(0, 1) < 0.3) { // 30% "collision" probability placeholder
        numCollisions++;
        emit(numCollisionsSignal, 1);

        simtime_t rt = exponential(meanRetransmit);
        scheduleAt(simTime() + rt, retransmitTimer);
    }
    else {
        transmitting = false;
    }
}

void AlohaMac::finish()
{
    cancelAndDelete(retransmitTimer);
    retransmitTimer = nullptr;

    while (!txQueue.isEmpty())
        delete txQueue.pop();

    recordScalar("numFromUpper", numFromUpper);
    recordScalar("numSent", numSent);
    recordScalar("numCollisions", numCollisions);
    recordScalar("numDropped", numDropped);
}
