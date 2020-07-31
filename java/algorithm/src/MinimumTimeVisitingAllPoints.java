public class MinimumTimeVisitingAllPoints {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Minimum
     * Time Visiting All Points. Memory Usage: 39.2 MB, less than 16.95% of Java
     * online submissions for Minimum Time Visiting All Points.
     */
    public int minTimeToVisitAllPoints(int[][] points) {
        if (points.length < 2) {
            return 0;
        }
        int min = 0, len = points.length;
        for (int pa = 0, pb = 1; pb < len; pa++, pb++) {
            int[] p1 = points[pa];
            int[] p2 = points[pb];
            int x_len = Math.abs(p1[0] - p2[0]);
            int y_len = Math.abs(p1[1] - p2[1]);
            min += Math.max(x_len, y_len);
        }
        return min;
    }

    public static void main(String[] args) {
        MinimumTimeVisitingAllPoints main = new MinimumTimeVisitingAllPoints();
        int[][] p1 = { { 1, 1 }, { 3, 4 }, { -1, 0 } };
        System.out.println(main.minTimeToVisitAllPoints(p1) == 7);

        int[][] p2 = { { 3, 2 }, { -2, 2 } };
        System.out.println(main.minTimeToVisitAllPoints(p2) == 5);
    }
}