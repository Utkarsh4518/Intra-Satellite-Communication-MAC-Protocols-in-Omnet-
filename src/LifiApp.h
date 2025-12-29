#ifndef __SATELLITE_LIFI_MAC_LIFIAPP_H
#define __SATELLITE_LIFI_MAC_LIFIAPP_H

#include <omnetpp.h>

using namespace omnetpp;

class LifiApp : public cSimpleModule
{
  private:
    cMessage *sendTimer = nullptr;
    double meanInterArrival;
    int packetLength;

    // statistics
    long numGenerated = 0;
    simsignal_t numGeneratedSignal;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

#endif
