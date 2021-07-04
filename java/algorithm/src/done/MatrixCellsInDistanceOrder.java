package done;

import java.util.Arrays;


public class MatrixCellsInDistanceOrder {
    /**
     * Runtime: 11 ms, faster than 65.12% of Java online submissions for Matrix Cells in Distance Order.
     * Memory Usage: 41.8 MB, less than 15.70% of Java online submissions for Matrix Cells in Distance Order.
     */
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int[][] arr = new int[rows * cols][2];
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++, index++) {
                arr[index][0] = i;
                arr[index][1] = j;
            }
        }
        Arrays.sort(arr, (o1, o2) -> {
            // |r1 - r2| + |c1 - c2|
            int d1 = Math.abs(o1[0] - rCenter) + Math.abs(o1[1] - cCenter);
            int d2 = Math.abs(o2[0] - rCenter) + Math.abs(o2[1] - cCenter);
            return d1 - d2;
        });
        return arr;
    }

    public static void main(String[] args) {
        MatrixCellsInDistanceOrder main = new MatrixCellsInDistanceOrder();
        main.allCellsDistOrder(2, 3, 0, 0);

    }
}
