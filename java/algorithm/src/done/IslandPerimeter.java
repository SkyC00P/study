package done;

/**
 * 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
 * <p>
 * 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * <p>
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长
 */
public class IslandPerimeter {
    /**
     * Runtime: 5 ms, faster than 99.58% of Java online submissions for Island Perimeter.
     * Memory Usage: 40.4 MB, less than 51.99% of Java online submissions for Island Perimeter.
     */
    public int islandPerimeter(int[][] grid) {
        int len = 0;
        for (int i = 0; i < grid.length; i++) {
            int[] arr = grid[i];
            for (int j = 0; j < arr.length; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int max = 4;
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    max--;
                }
                if (i + 1 < grid.length && grid[i + 1][j] == 1) {
                    max--;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    max--;
                }
                if (j + 1 < arr.length && grid[i][j + 1] == 1) {
                    max--;
                }
                len += max;
            }
        }
        return len;
    }

    public static void main(String[] args) {
        IslandPerimeter test = new IslandPerimeter();
        int[][] grid = new int[][]{
                new int[]{0, 1, 0, 0},
                new int[]{1, 1, 1, 0},
                new int[]{0, 1, 0, 0},
                new int[]{1, 1, 0, 0}
        };
        System.out.println(test.islandPerimeter(grid) == 16);
    }
}
