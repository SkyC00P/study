import java.util.ArrayList;

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * <p>
 * --------------
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * --------------
 * <p>
 * And then read line by line: "PAHNAPLSIIGYIR"
 * <p>
 * Write the code that will take a string and make this conversion given a number of rows:
 * <p>
 * string convert(string s, int numRows);
 * <p>
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * <p>
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * <p>
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
public class ZigZagConversion {

    /**
     * Runtime: 20 ms, faster than 84.83% of Java online submissions for ZigZag Conversion.
     * Memory Usage: 40.1 MB, less than 67.34% of Java online submissions for ZigZag Conversion.
     */
    public String convert(String s, int numRows) {
        if (s == null || s.length() < numRows || numRows == 1) {
            return s;
        }
        StringBuilder[] sb = new StringBuilder[numRows];
        for (int i = 0; i < sb.length; i++) {
            sb[i] = new StringBuilder();
        }
        int index = 0;
        boolean monotonicity = false;
        for (int i = 0; i < s.length(); i++) {
            sb[index].append(s.charAt(i));
            if(index == 0 || index == numRows - 1){
                monotonicity = !monotonicity;
            }
            index += monotonicity ? 1 : -1;
        }
        StringBuilder str = sb[0];
        for (int i = 1; i < sb.length; i++) {
            str.append(sb[i]);
        }
        return str.toString();
    }

    public static void main(String[] args) {
        ZigZagConversion solution = new ZigZagConversion();
        String str = solution.convert("PAYPALISHIRING", 3);
        System.out.println("PAHNAPLSIIGYIR".equals(str));
        str = solution.convert("AB",1);
        System.out.println();
    }
}
