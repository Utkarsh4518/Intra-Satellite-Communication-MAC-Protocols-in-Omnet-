package satellite_lifi_mac.simulations;

import satellite_lifi_mac.simulations.LifiNodeAloha;

network LifiNetworkAloha
{
    parameters:
        @display("bgb=400,300");
    submodules:
        nodeA: LifiNodeAloha { @display("p=80,150;l=A"); }
        nodeB: LifiNodeAloha { @display("p=180,80;l=B"); }
        nodeC: LifiNodeAloha { @display("p=280,150;l=C"); }
        nodeD: LifiNodeAloha { @display("p=180,220;l=D"); }
    connections allowunconnected:
        nodeA.out --> nodeB.in;
        nodeB.out --> nodeC.in;
        nodeC.out --> nodeD.in;
        nodeD.out --> nodeA.in;
}
