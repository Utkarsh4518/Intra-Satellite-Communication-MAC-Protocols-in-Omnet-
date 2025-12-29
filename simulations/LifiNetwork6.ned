package satellite_lifi_mac.simulations;

import satellite_lifi_mac.simulations.LifiNode;

network LifiNetwork6
{
    parameters:
        @display("bgb=500,350");
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
            @display("p=300,80;l=C");
        }
        nodeD: LifiNode {
            parameters: slotIndex = 3;
            @display("p=380,150;l=D");
        }
        nodeE: LifiNode {
            parameters: slotIndex = 4;
            @display("p=300,230;l=E");
        }
        nodeF: LifiNode {
            parameters: slotIndex = 5;
            @display("p=180,230;l=F");
        }
    connections allowunconnected:
        nodeA.out --> nodeB.in;
        nodeB.out --> nodeC.in;
        nodeC.out --> nodeD.in;
        nodeD.out --> nodeE.in;
        nodeE.out --> nodeF.in;
        nodeF.out --> nodeA.in;
}
