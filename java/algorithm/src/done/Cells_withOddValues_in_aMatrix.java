package done;

public class Cells_withOddValues_in_aMatrix {
    /**
     * Runtime: 1 ms, faster than 90.87% of Java online submissions for Cells with
     * Odd Values in a Matrix. Memory Usage: 37.3 MB, less than 86.85% of Java
     * online submissions for Cells with Odd Values in a Matrix.
     */
    public int oddCells(int n, int m, int[][] indices) {
        int[][] cells = new int[n][m];

        for (int i = 0; i < indices.length; i++) {
            int[] point = indices[i];
            increment_cell(point[0], point[1], cells);
        }

        int odd_nums = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((cells[i][j] & 1) == 1) {
                    odd_nums++;
                }
            }
        }
        return odd_nums;
    }

    private void increment_cell(int i, int j, int[][] cells) {
        for (int k = 0; k < cells.length; k++) {
            cells[k][j] = cells[k][j] += 1;
        }
        int[] arr = cells[i];
        for (int k = 0; k < arr.length; k++) {
            arr[k] = arr[k] + 1;
        }
    }

    public static void main(String[] args) {
        Cells_withOddValues_in_aMatrix main = new Cells_withOddValues_in_aMatrix();
        int[][] arr = { { 0, 1 }, { 1, 1 } };
        System.out.println(main.oddCells(2, 3, arr));
    }
}
