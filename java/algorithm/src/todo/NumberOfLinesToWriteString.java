package todo;

import java.util.Arrays;

public class NumberOfLinesToWriteString {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Number of Lines To Write String.
     * Memory Usage: 37.3 MB, less than 51.85% of Java online submissions for Number of Lines To Write String.
     */
    public int[] numberOfLines(int[] widths, String s) {
        int lines = 1;
        int width = 0;
        for (char ch : s.toCharArray()) {
            int w = widths[ch - 'a'];
            width += w;
            if (width > 100) {
                lines += 1;
                width = w;
            }
        }
        return new int[]{lines, width};
    }

    public static void main(String[] args) {
        int[] widths = new int[]{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        NumberOfLinesToWriteString main = new NumberOfLinesToWriteString();
        int[] arr = main.numberOfLines(widths, "abcdefghijklmnopqrstuvwxyz");
        System.out.println(Arrays.toString(arr));
    }
}
