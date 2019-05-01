public class NumberOf1Bits {
    /**
     * Runtime: 1 ms, faster than 29.53% of Java online submissions for Number of 1 Bits.
     * Memory Usage: 32 MB, less than 100.00% of Java online submissions for Number of 1 Bits.
     */
    public int hammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n == 0) break;
            if ((n & 1) == 1) count++;
            n = n >> 1;
        }
        return count;
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Number of 1 Bits.
     * Memory Usage: 32 MB, less than 100.00% of Java online submissions for Number of 1 Bits
     */
    public int hammingWeight_1(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
}
