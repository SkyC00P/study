package done;

public class ToeplitzMatrix {
    /**
     * Runtime: 1 ms, faster than 76.87% of Java online submissions for Toeplitz Matrix.
     * Memory Usage: 39 MB, less than 75.93% of Java online submissions for Toeplitz Matrix.
     */
    public boolean isToeplitzMatrix(int[][] matrix) {
        int row = matrix.length;
        int column = matrix[0].length;
        for (int i = 0, j = 0; j < column - 1; j++) {
            if (loop(matrix, row, column, j, i)) return false;
        }

        for (int j = 0, i = 1; i < row - 1; i++) {
            if (loop(matrix, row, column, j, i)) return false;
        }
        return true;
    }

    private boolean loop(int[][] matrix, int row, int column, int j, int i) {
        int m = i, n = j;
        while (m < row - 1 && n < column - 1) {
            if (matrix[m][n] != matrix[m + 1][n + 1]) return true;
            m += 1;
            n += 1;
        }
        return false;
    }

    public static void main(String[] args) {
        ToeplitzMatrix main = new ToeplitzMatrix();
        System.out.println(main.isToeplitzMatrix(new int[][]{
                {1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}
        }));
    }
}
