package done;

public class LongestUncommonSubsequence_I {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Longest
     * Uncommon Subsequence I . Memory Usage: 39 MB, less than 15.80% of Java online
     * submissions for Longest Uncommon Subsequence I .
     */
    public int findLUSlength(String a, String b) {
        if (a == null || a.isEmpty() || b == null || b.isEmpty() || a.equals(b)) {
            return -1;
        }
        return Math.max(a.length(), b.length());
    }
}
