package satellite_lifi_mac.simulations;

import satellite_lifi_mac.LifiApp;
import satellite_lifi_mac.TDMAMac;

module LifiNode
{
    parameters:
        int slotIndex = default(0);
        @display("i=device/pc");
    gates:
        input in;
        output out;
    submodules:
        app: LifiApp {
            @display("p=80,40");
        }
        mac: TDMAMac {
            parameters:
                nodeSlotIndex = parent.slotIndex;
            @display("p=80,120");
        }
    connections allowunconnected:
        app.out --> mac.upperIn;
        mac.lowerOut --> out;
        in --> mac.lowerIn;
}
