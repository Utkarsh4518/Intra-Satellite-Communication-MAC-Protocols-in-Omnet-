package satellite_lifi_mac;

simple LifiApp
{
    parameters:
        double meanInterArrival @unit(s) = default(0.05s);
        int packetLength = default(128);
        @display("i=block/app");
    gates:
        output out;
        input in;
}
