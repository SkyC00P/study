package todo;

import java.util.HashSet;
import java.util.Set;

public class TransposeMatrix {

    class Point {
        int x, y, v;

        public Point(int i, int j, int v) {
            this.x = x;
            this.y = y;
            this.v = v;
        }
    }

    public int[][] transpose(int[][] matrix) {
        Set<Point> set = new HashSet<>();
        for (int i = 0; i < matrix.length; i++) {
            int[] ar = matrix[i];
            for (int j = 0; j < ar.length; j++) {
                set.add(new Point(i, j, matrix[j][i]));
            }
        }
        for (Point p : set) {
            matrix[p.x][p.y] = p.v;
        }
        return matrix;
    }

}
