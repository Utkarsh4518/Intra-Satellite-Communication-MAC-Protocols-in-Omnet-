#ifndef __SATELLITE_LIFI_MAC_ALOHAMAC_H
#define __SATELLITE_LIFI_MAC_ALOHAMAC_H

#include <omnetpp.h>

using namespace omnetpp;

class AlohaMac : public cSimpleModule
{
  private:
    // parameters
    double meanRetransmit;  // seconds, for random retry after "collision"

    // state
    cMessage *retransmitTimer = nullptr;
    cQueue txQueue;
    bool transmitting = false;

    // statistics
    long numFromUpper = 0;
    long numSent = 0;
    long numCollisions = 0;
    long numDropped = 0;
    simsignal_t numFromUpperSignal;
    simsignal_t numSentSignal;
    simsignal_t numCollisionsSignal;
    simsignal_t numDroppedSignal;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

    void handleFromUpper(cMessage *msg);
    void handleRetransmitTimer();
    void tryTransmit();
};

#endif
