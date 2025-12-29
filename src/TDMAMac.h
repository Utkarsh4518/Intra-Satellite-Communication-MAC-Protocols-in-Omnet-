#ifndef __SATELLITE_LIFI_MAC_TDMAMAC_H
#define __SATELLITE_LIFI_MAC_TDMAMAC_H

#include <omnetpp.h>

using namespace omnetpp;

class TDMAMac : public cSimpleModule
{
  private:
    // parameters
    double slotLength;      // seconds
    int nodeSlotIndex;      // which slot belongs to this node
    int frameLength;        // number of slots per frame

    // state
    int currentSlot = 0;
    cMessage *slotTimer = nullptr;
    cQueue txQueue;         // packets from upper layer

    // statistics
    long numFromUpper = 0;
    long numSent = 0;
    simsignal_t numFromUpperSignal;
    simsignal_t numSentSignal;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

    void handleFromUpper(cMessage *msg);
    void handleSlotTimer();
};

#endif
