public class RangeAddition_II {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Range
     * Addition II. Memory Usage: 38.9 MB, less than 100.00% of Java online
     * submissions for Range Addition II.
     */
    public int maxCount(int m, int n, int[][] ops) {
        if (ops == null || ops.length == 0) {
            return m * n;
        }
        int w_min = Integer.MAX_VALUE;
        int h_win = Integer.MAX_VALUE;
        for (int i = 0; i < ops.length; i++) {
            int[] op = ops[i];
            w_min = Math.min(w_min, op[0]);
            h_win = Math.min(h_win, op[1]);
        }
        return w_min * h_win;
    }
}
