package done;

public class CountAndSay {
    /**
     * Runtime: 1 ms, faster than 99.73% of Java online submissions for Count and Say.
     * Memory Usage: 35.6 MB, less than 99.84% of Java online submissions for Count and Say.
     */
    public String countAndSay(int n) {
        return countAndSay_1("1", n);
    }

    private String countAndSay_1(String s, int n) {
        if (n == 1) return s;
        String str = sayTheStr(s);
        return countAndSay_1(str, n - 1);
    }

    private String sayTheStr(String s) {
        if (s.length() == 1) return "1" + s;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ) {
            char ch = s.charAt(i);
            int count = 1;
            int j = i + 1;
            while (j < s.length() && s.charAt(j) == ch) {
                count++;
                j++;
            }
            sb.append(count).append(ch);
            i = j;
        }
        return sb.toString();
    }

}
