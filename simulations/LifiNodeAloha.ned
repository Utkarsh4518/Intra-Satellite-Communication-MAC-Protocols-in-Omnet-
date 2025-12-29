package satellite_lifi_mac.simulations;

import satellite_lifi_mac.LifiApp;
import satellite_lifi_mac.AlohaMac;

module LifiNodeAloha
{
    parameters:
        @display("i=device/pc");
    gates:
        input in;
        output out;
    submodules:
        app: LifiApp {
            @display("p=80,40");
        }
        mac: AlohaMac {
            @display("p=80,120");
        }
    connections allowunconnected:
        app.out --> mac.upperIn;
        mac.lowerOut --> out;
        in --> mac.lowerIn;
}
