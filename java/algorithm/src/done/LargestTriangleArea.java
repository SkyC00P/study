package done;

public class LargestTriangleArea {
    /**
     * Runtime: 5 ms, faster than 63.10% of Java online submissions for Largest Triangle Area.
     * Memory Usage: 37.2 MB, less than 26.59% of Java online submissions for Largest Triangle Area.
     */
    public double largestTriangleArea(int[][] points) {
        double max = 0;
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                for (int k = j + 1; k < points.length; k++) {
                    int[] P = points[i];
                    int[] Q = points[j];
                    int[] R = points[k];

                    double area = 0.5 * Math.abs(P[0] * Q[1] + Q[0] * R[1] + R[0] * P[1]
                            - P[1] * Q[0] - Q[1] * R[0] - R[1] * P[0]);

                    if (area > max) {
                        max = area;
                    }
                }
            }
        }
        return max;
    }
}
