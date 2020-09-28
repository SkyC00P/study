public class Maximum69Number {
    /**
     * Runtime: 4 ms, faster than 24.65% of Java online submissions for Maximum 69
     * Number. Memory Usage: 36.3 MB, less than 67.87% of Java online submissions
     * for Maximum 69 Number.
     */
    public int maximum69Number(int num) {
        String s_num = num + "";
        char[] chs = s_num.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            if (chs[i] == '6') {
                chs[i] = '9';
                break;
            }
        }
        return Integer.parseInt(new String(chs));
    }
}
