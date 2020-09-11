import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Shift2DGrid {
    /**
     * Runtime: 5 ms, faster than 77.88% of Java online submissions for Shift 2D
     * Grid. Memory Usage: 40.5 MB, less than 39.32% of Java online submissions for
     * Shift 2D Grid.
     */
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        List<List<Integer>> list = new ArrayList<>();
        Deque<Integer> deque = new ArrayDeque<>();
        for (int[] i : grid) {
            for (int j : i) {
                deque.add(j);
            }
        }
        for (int i = 0; i < k; i++) {
            deque.addFirst(deque.removeLast());
        }
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            List<Integer> m_list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                m_list.add(deque.removeFirst());
            }
            list.add(m_list);
        }
        return list;
    }
}
