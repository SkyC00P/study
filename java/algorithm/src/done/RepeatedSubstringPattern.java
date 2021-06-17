package done;

public class RepeatedSubstringPattern {
    /**
     * Runtime: 20 ms, faster than 55.38% of Java online submissions for Repeated Substring Pattern.
     * Memory Usage: 36.7 MB, less than 100.00% of Java online submissions for Repeated Substring Pattern.
     */
    public boolean repeatedSubstringPattern(String s) {
        if (s == null || s.length() <= 1) return false;
        boolean isAllEqu = true;
        for (int i = 1; i < s.length(); i++) {
            isAllEqu = s.charAt(0) == s.charAt(i);
            if (!isAllEqu) break;
        }
        if (isAllEqu) return true;

        int len = s.length();
        for (int i = 2; i <= (len / 2); i++) {
            if (len % i != 0) {
                continue;
            }
            boolean isSuc = true;
            int frame = len / i;
            find:
            for (int j = 0; j < frame; j++) {
                for (int k = 1; k < i; k++) {
                    if (s.charAt(j) != s.charAt(j + frame * k)) {
                        isSuc = false;
                        break find;
                    }
                }
            }

            if (isSuc) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        RepeatedSubstringPattern test = new RepeatedSubstringPattern();
        boolean b = test.repeatedSubstringPattern("abababac");
        System.out.println(b);
        b = test.repeatedSubstringPattern("bb");
        System.out.println(b);
        b = test.repeatedSubstringPattern("babbabbabbabbab");
        System.out.println(b);
        b = test.repeatedSubstringPattern("zzz");
        System.out.println(b);
    }
}
