package done;

public class ValidPalindromeII {

    /**
     * Runtime: 45 ms, faster than 5.58% of Java online submissions for Valid Palindrome II.
     * Memory Usage: 58.2 MB, less than 5.84% of Java online submissions for Valid Palindrome II.
     */
    public boolean validPalindrome(String s) {
        return validSubPalindrome(s, 0, s.length() - 1, false);
    }

    private boolean validSubPalindrome(String s, int lo, int hi, boolean used) {
        if (lo >= hi) { // base case
            return true;
        }

        if (s.charAt(lo) != s.charAt(hi)) { // equal
            if (!used) {
                if (validSubPalindrome(s, lo + 1, hi, true)) return true; // test left deletion
                return validSubPalindrome(s, lo, hi - 1, true); // test right deletion
            } else {
                return false;
            }
        }

        return validSubPalindrome(s, lo + 1, hi - 1, used);
    }

    /**
     * Time Limit Exceeded
     */
    public boolean validPalindrome_fail(String s) {
        if (isPalindromeWhenNotDel(s)) return true;
        for (int i = 0; i < s.length(); i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < s.length(); j++) {
                if (i == j) continue;
                sb.append(s.charAt(j));
            }
            if (isPalindromeWhenNotDel(sb.toString())) return true;
        }
        return false;
    }

    public boolean isPalindromeWhenNotDel(String s) {
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
