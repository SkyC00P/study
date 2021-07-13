package done;

public class _1_bitAnd2_bitCharacters {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for 1-bit and 2-bit Characters.
     * Memory Usage: 38.3 MB, less than 66.87% of Java online submissions for 1-bit and 2-bit Characters.
     */
    public boolean isOneBitCharacter(int[] bits) {
        for (int i = 0; i < bits.length - 1; i++) {
            int bit = bits[i];
            if (bit == 1) {
                if (i + 1 < bits.length - 1) i++;
                else return false;
            }
        }
        return true;
    }
}
