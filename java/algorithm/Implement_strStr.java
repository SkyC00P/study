public class Implement_strStr {

    /**
     * ? kmp 算法
     * 朴素kmp算法，看看有多慢
     * Runtime: 406 ms, faster than 6.26% of Java online submissions for Implement strStr().
     * Memory Usage: 38.3 MB, less than 51.79% of Java online submissions for Implement strStr().
     */
    public int strStr1(String haystack, String needle) {

        if (needle == null || needle.isEmpty()) return 0;
        if (needle.length() > haystack.length()) return -1;

        char[] chs = needle.toCharArray();
        for (int i = 0; i < haystack.length(); i++) {
            boolean match = true;
            int j, k;
            for (j = 0, k = i; j < chs.length; j++, k++) {
                if (k >= haystack.length() || haystack.charAt(k) != chs[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }

    /**
     * 标准KMP算法实现 2ms 跟 400ms的差别
     * Runtime: 2 ms, faster than 95.79% of Java online submissions for Implement strStr().
     * Memory Usage: 38.8 MB, less than 10.01% of Java online submissions for Implement strStr().
     */
    public int strStr(String haystack, String needle) {

        if (needle == null || needle.isEmpty()) return 0;
        if (needle.length() > haystack.length()) return -1;

        char[] t = haystack.toCharArray();
        char[] p = needle.toCharArray();

        int i = 0; // 主串的位置
        int j = 0; // 模式串的位置

        int[] next = getNext(needle);

        while (i < t.length && j < p.length) {
            if (j == -1 || t[i] == p[j]) { // 当j为-1时，要移动的是i，当然j也要归0
                i++;
                j++;
            } else {
                j = next[j]; // j回到指定位置
            }
        }

        if (j == p.length) {
            return i - j;
        } else {
            return -1;
        }
    }

    public static int[] getNext(String ps) {

        char[] p = ps.toCharArray();
        int[] next = new int[p.length];
        next[0] = -1;
        int j = 0;
        int k = -1;

        while (j < p.length - 1) {
            if (k == -1 || p[j] == p[k]) {
                if (p[++j] == p[++k]) { // 当两个字符相等时要跳过
                    next[j] = next[k];
                } else {
                    next[j] = k;
                }
            } else {
                k = next[k];
            }
        }
        return next;
    }

    public static void main(String[] args) {
        Implement_strStr solution = new Implement_strStr();
        System.out.println(solution.strStr("hello", "ll") == 2);
        System.out.println(solution.strStr("aaaaa", "bba") == -1);
        System.out.println(solution.strStr("aaa", "aaaa") == -1);
        System.out.println(solution.strStr("mississippi", "issipi") == -1);
        System.out.println(solution.strStr("", "") == 0);
        System.out.println(solution.strStr("1", "") == 0);
        System.out.println(solution.strStr("", "1") == -1);
    }
}
