package done;

public class IsSubsequence {
    /**
     * Runtime: 15 ms, faster than 61.21% of Java online submissions for Is Subsequence.
     * Memory Usage: 49.2 MB, less than 100.00% of Java online submissions for Is Subsequence.
     */
    public boolean isSubsequence(String s, String t) {
        int read = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int old = read;
            for (int j = read; j < t.length(); j++) {
                if (ch == t.charAt(j)) {
                    read = j + 1;
                    break;
                }
            }
            if (old == read) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        IsSubsequence test = new IsSubsequence();
        System.out.println(test.isSubsequence("abc", "ahbgdc"));
        System.out.println(test.isSubsequence("axc", "ahbgdc"));
    }
}
