package done;

public class BinaryNumberWithAlternatingBits {
    /**
     * Runtime: 1 ms, faster than 19.17% of Java online submissions for Binary Number with Alternating Bits.
     * Memory Usage: 37.9 MB, less than 6.39% of Java online submissions for Binary Number with Alternating Bits.
     */
    public boolean hasAlternatingBits(int n) {
        String bs = Integer.toBinaryString(n);
        for (int i = 0; i < bs.length() - 1; i++) {
            char ch_1 = bs.charAt(i);
            char ch_2 = bs.charAt(i + 1);
            if (ch_1 == ch_2) return false;
        }
        return true;
    }
}
