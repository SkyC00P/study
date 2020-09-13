import java.util.HashSet;
import java.util.Set;

public class PathCrossing {
    /**
     * Runtime: 10 ms, faster than 14.54% of Java online submissions for Path
     * Crossing. Memory Usage: 40.5 MB, less than 5.05% of Java online submissions
     * for Path Crossing.
     */
    public boolean isPathCrossing(String path) {
        Set<String> point = new HashSet<>();
        int[] last_point = new int[] { 0, 0 };
        point.add("0 0");
        for (char ch : path.toCharArray()) {
            int[] next_point = getNextPoint(ch, last_point);
            String key = next_point[0] + " " + next_point[1];
            if (point.contains(key)) {
                return true;
            }
            point.add(key);
            last_point = next_point;
        }
        return false;
    }

    private int[] getNextPoint(char ch, int[] last_point) {
        int[] point = new int[2];
        switch (ch) {
            case 'N':
                point[0] = last_point[0];
                point[1] = last_point[1] + 1;
                break;
            case 'S':
                point[0] = last_point[0];
                point[1] = last_point[1] - 1;
                break;
            case 'E':
                point[0] = last_point[0] + 1;
                point[1] = last_point[1];
                break;
            case 'W':
                point[0] = last_point[0] - 1;
                point[1] = last_point[1];
                break;
        }
        return point;
    }
}
