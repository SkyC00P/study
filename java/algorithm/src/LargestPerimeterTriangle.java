import java.util.Arrays;

public class LargestPerimeterTriangle {
    /**
     * Runtime: 7 ms, faster than 70.78% of Java online submissions for Largest
     * Perimeter Triangle. Memory Usage: 39.9 MB, less than 80.75% of Java online
     * submissions for Largest Perimeter Triangle.
     */
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        for (int len = A.length; len - 3 >= 0; len -= 3) {
            int a = A[len - 1];
            int b = A[len - 2];
            int c = A[len - 3];
            if (a + b > c && a + c > b && b + c > a) {
                return a + b + c;
            }
        }
        return 0;
    }
}