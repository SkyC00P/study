import java.util.Arrays;

public class Generate_a_StringWithCharactersThatHaveOddCounts {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Generate a
     * String With Characters That Have Odd Counts. Memory Usage: 36.8 MB, less than
     * 83.20% of Java online submissions for Generate a String With Characters
     */
    public String generateTheString(int n) {
        char[] chs = new char[n];
        Arrays.fill(chs, 'a');
        if ((n & 1) == 0) {
            chs[0] = 'b';
        }
        return new String(chs);
    }
}