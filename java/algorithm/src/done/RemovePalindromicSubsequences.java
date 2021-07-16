package done;

public class RemovePalindromicSubsequences {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Palindromic Subsequences.
     * Memory Usage: 36.5 MB, less than 97.85% of Java online submissions for Remove Palindromic Subsequences.
     */
    public int removePalindromeSub(String s) {
        if (s == null || s.isEmpty()) return 0;
        return isPalindrome(s) ? 1 : 2;
    }

    public boolean isPalindrome(String s) {
        if (s == null || s.isEmpty() || s.length() == 1) {
            return true;
        }

        int start = 0, end = s.length() - 1;
        while (true) {
            start = getFirstChar(s, start, end);
            end = getLastChar(s, start, end);

            if (start < 0 || end < 0) {
                break;
            }
            char ch1 = Character.toLowerCase(s.charAt(start));
            char ch2 = Character.toLowerCase(s.charAt(end));
            if (ch1 != ch2) return false;
            start += 1;
            end -= 1;
        }

        return true;

    }

    private int getLastChar(String s, int start, int end) {
        for (int i = end; i > start; i--) {
            if (Character.isLetterOrDigit(s.charAt(i))) return i;
        }
        return -1;
    }

    private int getFirstChar(String s, int start, int end) {
        for (int i = start; i < end; i++) {
            if (Character.isLetterOrDigit(s.charAt(i))) return i;
        }
        return -1;
    }
}
