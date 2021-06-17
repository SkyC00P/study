package done;

public class CountNegativeNumbersInASortedMatrix {
    /**
     * Runtime: 1 ms, faster than 48.34% of Java online submissions for Count Negative Numbers in a Sorted Matrix.
     * Memory Usage: 39.3 MB, less than 65.18% of Java online submissions for Count Negative Numbers in a Sorted Matrix.
     */
    public int countNegatives(int[][] grid) {
        if (grid == null) return 0;
        int count = 0;
        for (int[] arr : grid) {
            for (int i : arr) {
                if (i < 0) count++;
            }
        }
        return count;
    }
}
