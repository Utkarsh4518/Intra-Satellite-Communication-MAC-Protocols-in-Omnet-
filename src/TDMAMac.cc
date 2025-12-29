#include "TDMAMac.h"

Define_Module(TDMAMac);

void TDMAMac::initialize()
{
    slotLength = par("slotLength").doubleValue();
    nodeSlotIndex = par("nodeSlotIndex").intValue();
    frameLength = par("frameLength").intValue();
    if (frameLength <= 0)
        frameLength = 4; // fallback

    // statistics
    numFromUpper = 0;
    numSent = 0;
    numFromUpperSignal = registerSignal("numFromUpper");
    numSentSignal = registerSignal("numSent");

    slotTimer = new cMessage("slotTimer");
    scheduleAt(simTime() + slotLength, slotTimer);
}

void TDMAMac::handleMessage(cMessage *msg)
{
    if (msg == slotTimer) {
        handleSlotTimer();
    }
    else {
        // everything else is considered from upper layer
        handleFromUpper(msg);
    }
}

void TDMAMac::handleFromUpper(cMessage *msg)
{
    numFromUpper++;
    emit(numFromUpperSignal, 1);
    txQueue.insert(msg);
}

void TDMAMac::handleSlotTimer()
{
    // Is this our slot?
    if (currentSlot == nodeSlotIndex) {
        if (!txQueue.isEmpty()) {
            cMessage *pkt = (cMessage *)txQueue.pop();

            numSent++;
            emit(numSentSignal, 1);

            send(pkt, "lowerOut");
        }
    }

    currentSlot = (currentSlot + 1) % frameLength;
    scheduleAt(simTime() + slotLength, slotTimer);
}

void TDMAMac::finish()
{
    cancelAndDelete(slotTimer);
    slotTimer = nullptr;

    while (!txQueue.isEmpty()) {
        delete txQueue.pop();
    }

    recordScalar("numFromUpper", numFromUpper);
    recordScalar("numSent", numSent);
}

