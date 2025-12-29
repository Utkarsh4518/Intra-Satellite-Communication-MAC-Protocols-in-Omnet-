package satellite_lifi_mac;

simple CSMAMac
{
    parameters:
        double meanBackoff @unit(s) = default(0.005s); // 5 ms
        @display("i=block/layer");
    gates:
        input upperIn;
        output upperOut;   // reserved for future use
        input lowerIn;
        output lowerOut;

}
