package done;

public class ExcelSheetColumnNumber {
    /**
     * Runtime: 1 ms, faster than 99.91% of Java online submissions for Excel Sheet Column Number.
     * Memory Usage: 36.9 MB, less than 64.69% of Java online submissions for Excel Sheet Column Number
     */
    public int titleToNumber(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        double num = 0;
        char[] chs = s.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            double k = (chs[i] - 'A' + 1) * Math.pow(26, chs.length - i - 1);
            num += k;
        }

        return (int) num;
    }
}
