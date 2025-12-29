package satellite_lifi_mac.simulations;

import satellite_lifi_mac.simulations.LifiNode;

network LifiNetwork8
{
    parameters:
        @display("bgb=600,400");
    submodules:
        nodeA: LifiNode {
            parameters: slotIndex = 0;
            @display("p=80,200;l=A");
        }
        nodeB: LifiNode {
            parameters: slotIndex = 1;
            @display("p=150,100;l=B");
        }
        nodeC: LifiNode {
            parameters: slotIndex = 2;
            @display("p=260,80;l=C");
        }
        nodeD: LifiNode {
            parameters: slotIndex = 3;
            @display("p=370,100;l=D");
        }
        nodeE: LifiNode {
            parameters: slotIndex = 4;
            @display("p=440,200;l=E");
        }
        nodeF: LifiNode {
            parameters: slotIndex = 5;
            @display("p=370,300;l=F");
        }
        nodeG: LifiNode {
            parameters: slotIndex = 6;
            @display("p=260,320;l=G");
        }
        nodeH: LifiNode {
            parameters: slotIndex = 7;
            @display("p=150,300;l=H");
        }
    connections allowunconnected:
        nodeA.out --> nodeB.in;
        nodeB.out --> nodeC.in;
        nodeC.out --> nodeD.in;
        nodeD.out --> nodeE.in;
        nodeE.out --> nodeF.in;
        nodeF.out --> nodeG.in;
        nodeG.out --> nodeH.in;
        nodeH.out --> nodeA.in;
}
