public class MatrixDiagonalSum {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Matrix
     * Diagonal Sum. Memory Usage: 39 MB, less than 98.60% of Java online
     * submissions for Matrix Diagonal Sum.
     */
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        for (int i = 0, j = mat.length - 1; i < mat.length; i++, j--) {
            sum += mat[i][i];
            sum += mat[i][j];
        }
        if ((mat.length & 1) == 1) {
            int len = mat.length;
            sum -= mat[len / 2][len / 2];
        }
        return sum;
    }

    public static void main(String[] args) {
        MatrixDiagonalSum main = new MatrixDiagonalSum();
        System.out.println(
                main.diagonalSum(new int[][] { { 7, 3, 1, 9 }, { 3, 4, 6, 9 }, { 6, 9, 6, 6 }, { 9, 5, 8, 5 } }));
    }
}
