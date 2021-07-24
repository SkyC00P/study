package done;

import utils.ArrayUtils;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class TransposeMatrix {

    class Point {
        int x, y, v;

        public Point(int x, int y, int v) {
            this.x = x;
            this.y = y;
            this.v = v;
        }
    }

    /**
     * Runtime: 4 ms, faster than 24.79% of Java online submissions for Transpose Matrix.
     * Memory Usage: 39.4 MB, less than 96.05% of Java online submissions for Transpose Matrix.
     */
    public int[][] transpose(int[][] matrix) {
        Set<Point> set = new HashSet<>();
        int r = matrix.length;
        int c = matrix[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                set.add(new Point(j, i, matrix[i][j]));
            }
        }
        int[][] arr = new int[c][r];
        for (Point p : set) {
            arr[p.x][p.y] = p.v;
        }
        return arr;
    }

    public static void main(String[] args) {
        int[][] arr = ArrayUtils.toArray("[[1,2,3],[4,5,6],[7,8,9]]");
        TransposeMatrix main = new TransposeMatrix();
        System.out.println(Arrays.deepToString(main.transpose(arr)));
        // [[1,4],[2,5],[3,6]]
        // 123  2 * 3  00->00 01->10 02->x  10->01
        // 456
        arr = ArrayUtils.toArray("[[1,2,3],[4,5,6]]");
        System.out.println(Arrays.deepToString(main.transpose(arr)));
    }

}
