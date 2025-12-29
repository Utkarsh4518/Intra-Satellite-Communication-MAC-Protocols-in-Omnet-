package satellite_lifi_mac.simulations;

import satellite_lifi_mac.simulations.LifiNode;

network LifiNetwork
{
    parameters:
        @display("bgb=400,300");
    submodules:
        nodeA: LifiNode {
            parameters: slotIndex = 0;
            @display("p=80,150;l=A");
        }
        nodeB: LifiNode {
            parameters: slotIndex = 1;
            @display("p=180,80;l=B");
        }
        nodeC: LifiNode {
            parameters: slotIndex = 2;
            @display("p=280,150;l=C");
        }
        nodeD: LifiNode {
            parameters: slotIndex = 3;
            @display("p=180,220;l=D");
        }
    connections allowunconnected:
        nodeA.out --> nodeB.in;
        nodeB.out --> nodeC.in;
        nodeC.out --> nodeD.in;
        nodeD.out --> nodeA.in;
}
