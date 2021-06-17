package done;

import java.util.HashMap;

/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * <p>
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * <p>
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 * <p>
 * 这个算法得明白什么是回文串，动态规划，还有字符串操作，LeetCode 提供了5种解法
 */
public class LongestPalindrome {

    /**
     * 暴力解法
     * 输入为 :esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq
     * 过不了：因为这个解法是指数级的
     * Time Limit Exceeded
     */
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        int max = 1;
        String str = s.charAt(0) + "";
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                t1++;
                String sub = s.substring(i, j + 1);
                if (CheckIsPalindrome(sub) && sub.length() > max) {
                    max = sub.length();
                    str = sub;
                }
            }
        }
        System.out.println(s + " -->f1:size=" + s.length() + ",times=" + t1);
        t1 = 0;
        return str;
    }

    static int t1 = 0;
    static int t2 = 0;

    /**
     * 动态规划解法
     */
    public String longestPalindrome_1(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        int n = s.length();
        String res = null;

        boolean[][] dp = new boolean[n][n];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);

                if (dp[i][j] && (res == null || j - i + 1 > res.length())) {
                    res = s.substring(i, j + 1);
                }
            }
        }
        System.out.println(s + " --> f2:size=" + s.length() + ",times=" + t1);
        t1 = 0;
        return res;
    }

    private boolean CheckIsPalindrome(String s) {
        if (s == null || s.length() == 0) {
            throw new IllegalArgumentException("str is null or empty");
        }
        String str = new StringBuffer(s).reverse().toString();
        return str.equals(s);
    }

    /**
     * Runtime: 6 ms, faster than 29.25% of Java online submissions for Longest Palindrome.
     * Memory Usage: 35.5 MB, less than 98.79% of Java online submissions for Longest Palindrome
     */
    public int _longestPalindrome(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char ch : s.toCharArray()) {
            if (map.containsKey(ch)) map.put(ch, map.get(ch) + 1);
            else map.put(ch, 1);
        }
        int len = 0;
        boolean notOddNumber = true;
        for (char ch : map.keySet()) {
            int num = map.get(ch);
            len = (num & 1) == 0 ? len + num : len + num - 1;
            notOddNumber &= (num & 1) == 0;
        }
        return notOddNumber ? len : len + 1;
    }

    public static void main(String[] args) {
        LongestPalindrome solution = new LongestPalindrome();
        String s1 = "babad";
        String s2 = "cbbd";
        String s3 = "esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq";
        System.out.println(solution.longestPalindrome(s1));
        System.out.println(solution.longestPalindrome(s2));
        long t = System.currentTimeMillis();
        System.out.println(t);
        System.out.println(solution.longestPalindrome(s3));
        System.out.println(System.currentTimeMillis() + " " + (System.currentTimeMillis() - t));

        System.out.println(solution.longestPalindrome_1(s1));
    }
}
