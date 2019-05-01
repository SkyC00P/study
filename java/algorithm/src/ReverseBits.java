// you need treat n as an unsigned value
public class ReverseBits {

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Reverse Bits.
     * Memory Usage: 27.8 MB, less than 95.57% of Java online submissions for Reverse Bits.
     */
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            // n & 1 取 n的最低位
            // res 左移一位存 n&1 的值
            res = (res << 1) | (n & 1);
            // n >> 1 舍弃n的最低位
            n = n >> 1;
        }
        return res;
    }
}
