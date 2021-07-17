package done;

public class ReshapeTheMatrix {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Reshape the Matrix.
     * Memory Usage: 39.9 MB, less than 54.93% of Java online submissions for Reshape the Matrix.
     */
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int _r = mat.length;
        int _c = mat[0].length;
        int n = r * c;
        int _n = _r * _c;
        if (n != _n) return mat;

        int[][] _mat = new int[r][c];
        int row = 0, col = 0;
        for (int[] ints : mat) {
            for (int j = 0; j < _c; j++) {
                _mat[row][col] = ints[j];
                col++;
                if (col == c) {
                    row++;
                    col = 0;
                }
            }
        }
        return _mat;
    }
}
