import java.util.Arrays;

public class HeightChecker {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Height
     * Checker. Memory Usage: 37 MB, less than 90.57% of Java online submissions for
     * Height Checker.
     */
    public int heightChecker(int[] heights) {
        int[] arr = Arrays.copyOf(heights, heights.length);
        Arrays.sort(heights);
        int n = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != arr[i])
                n++;
        }
        return n;
    }
}