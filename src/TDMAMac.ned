package satellite_lifi_mac;

simple TDMAMac
{
    parameters:
        double slotLength @unit(s) = default(0.01s); // 10 ms
        int nodeSlotIndex = default(0);             // 0..frameLength-1
        int frameLength = default(4);
        @display("i=block/layer");
    gates:
        input upperIn;
        output upperOut;  // not used yet, but kept for symmetry
        input lowerIn;
        output lowerOut;
}
