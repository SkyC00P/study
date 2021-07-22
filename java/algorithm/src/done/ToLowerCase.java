package done;

public class ToLowerCase {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for To Lower Case.
     * Memory Usage: 37.5 MB, less than 12.14% of Java online submissions for To Lower Case.
     */
    public String toLowerCase(String s) {
        char[] chs = s.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            char ch = chs[i];
            if (ch >= 'A' && ch <= 'Z') {
                chs[i] = (char) (ch + 32);
            }
        }
        return new String(chs);
    }
}
