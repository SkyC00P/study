package done;

import java.util.*;

public class FloodFill {
    class Point {
        int x, y;
        int color;

        public Point(int sr, int sc, int newColor) {
            this.x = sr;
            this.y = sc;
            this.color = newColor;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x &&
                    y == point.y &&
                    color == point.color;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y, color);
        }

        public Point getLeft(int[][] image) {
            return y > 0 && image[x][y - 1] == color ? new Point(x, y - 1, color) : null;
        }

        public Point getRight(int[][] image) {
            return y + 1 < image[0].length && image[x][y + 1] == color ? new Point(x, y + 1, color) : null;
        }

        public Point getTop(int[][] image) {
            return x + 1 < image.length && image[x + 1][y] == color ? new Point(x + 1, y, color) : null;
        }

        public Point getBottom(int[][] image) {
            return x > 0 && image[x - 1][y] == color ? new Point(x - 1, y, color) : null;
        }
    }

    /**
     * Runtime: 2 ms, faster than 20.06% of Java online submissions for Flood Fill.
     * Memory Usage: 40.2 MB, less than 24.55% of Java online submissions for Flood Fill.
     */
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        // 已染色
        Set<Point> fps = new HashSet<>();
        // 未染色
        Queue<Point> ps = new ArrayDeque<>();

        Point p = new Point(sr, sc, image[sr][sc]);

        do {
            image[p.x][p.y] = newColor;
            fps.add(p);

            // 将该点的左右上下加入队列
            addIfNotNull(ps, fps, p.getLeft(image));
            addIfNotNull(ps, fps, p.getRight(image));
            addIfNotNull(ps, fps, p.getTop(image));
            addIfNotNull(ps, fps, p.getBottom(image));

            p = ps.poll();
        } while (p != null);

        return image;
    }

    private void addIfNotNull(Queue<Point> ps, Set<Point> fps, Point p) {
        if (p != null && !fps.contains(p)) ps.add(p);
    }
}
