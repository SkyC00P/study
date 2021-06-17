package done;

public class SpecialPositionsInABinaryMatrix {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Special
     * Positions in a Binary Matrix. Memory Usage: 39.6 MB, less than 75.00% of Java
     * online submissions for Special Positions in a Binary Matrix.
     */
    public int numSpecial(int[][] mat) {
        int count = 0;
        for (int row = 0; row < mat.length; row++) {
            int[] cols = mat[row];
            for (int col = 0; col < cols.length; col++) {
                if (mat[row][col] == 1) {
                    if (isSpecial(row, col, mat)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    private boolean isSpecial(int row, int col, int[][] mat) {
        for (int i = 0; i < mat.length; i++) {
            if (i != row && mat[i][col] == 1) {
                return false;
            }
        }

        for (int i = 0; i < mat[0].length; i++) {
            if (i != col && mat[row][i] == 1) {
                return false;
            }
        }
        return true;
    }
}
