package satellite_lifi_mac;

simple AlohaMac
{
    parameters:
        double meanRetransmit @unit(s) = default(0.05s);
        @display("i=block/layer");
    gates:
        input upperIn;
        output upperOut;   // reserved
        input lowerIn;
        output lowerOut;

}
