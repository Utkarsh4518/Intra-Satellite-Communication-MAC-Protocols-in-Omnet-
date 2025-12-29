#ifndef __SATELLITE_LIFI_MAC_CSMAMAC_H
#define __SATELLITE_LIFI_MAC_CSMAMAC_H

#include <omnetpp.h>

using namespace omnetpp;

class CSMAMac : public cSimpleModule
{
  private:
    // parameters
    double meanBackoff;     // seconds

    // state
    cMessage *backoffTimer = nullptr;
    cQueue txQueue;
    bool channelBusy = false; // simplified, updated via parameter/event later

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
    void handleBackoffTimer();
    void handleFromLower(cMessage *msg);   // add this
    void tryTransmit();
};

#endif
