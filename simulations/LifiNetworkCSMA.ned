package satellite_lifi_mac.simulations;

import satellite_lifi_mac.simulations.LifiNodeCSMA;

network LifiNetworkCSMA
{
    parameters:
        @display("bgb=400,300");
    submodules:
        nodeA: LifiNodeCSMA { @display("p=80,150;l=A"); }
        nodeB: LifiNodeCSMA { @display("p=180,80;l=B"); }
        nodeC: LifiNodeCSMA { @display("p=280,150;l=C"); }
        nodeD: LifiNodeCSMA { @display("p=180,220;l=D"); }
    connections allowunconnected:
        nodeA.out --> nodeB.in;
        nodeB.out --> nodeC.in;
        nodeC.out --> nodeD.in;
        nodeD.out --> nodeA.in;
}
