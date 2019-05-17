public class ReverseString {

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Reverse String.
     * Memory Usage: 46.7 MB, less than 65.44% of Java online submissions for Reverse String.
     */
    public void reverseString(char[] s) {
        if (s == null || s.length <= 1) {
            return;
        }

        int exChange = s.length / 2;
        for (int i = 0; i < exChange; i++) {
            char k = s[i];
            s[i] = s[s.length - i - 1];
            s[s.length - i - 1] = k;
        }
    }
}
