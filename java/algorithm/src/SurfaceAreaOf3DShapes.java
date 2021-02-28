public class SurfaceAreaOf3DShapes {
    public int surfaceArea(int[][] grid) {
        int[] dr = new int[]{0, 1, 0, -1};
        int[] dc = new int[]{1, 0, -1, 0};

        int N = grid.length;
        int ans = 0;

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                if (grid[r][c] > 0) {
                    ans += 2;
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        int nv = 0;
                        if (0 <= nr && nr < N && 0 <= nc && nc < N)
                            nv = grid[nr][nc];

                        ans += Math.max(grid[r][c] - nv, 0);
                    }
                }

        return ans;
    }

    public static void main(String[] args) {
        SurfaceAreaOf3DShapes q = new SurfaceAreaOf3DShapes();
        // [[1,1,1],[1,0,1],[1,1,1]] 16 + 6 + 6
        System.out.println(q.surfaceArea(new int[][]{
                new int[]{1, 1, 1},
                new int[]{1, 0, 1},
                new int[]{1, 1, 1}
        }));
        System.out.println(q.surfaceArea(new int[][]{
                new int[]{1, 2},
                new int[]{3, 4}
        }));
    }
}
