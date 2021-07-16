package done;

import java.util.ArrayList;
import java.util.List;

public class MostVisitedSector_in_aCircularTrack {
    /**
     * Runtime: 2 ms, faster than 54.70% of Java online submissions for Most Visited Sector in a Circular Track.
     * Memory Usage: 39.2 MB, less than 60.68% of Java online submissions for Most Visited Sector in a Circular Track.
     */
    public List<Integer> mostVisited(int n, int[] rounds) {
        int offset = 0, index = rounds[0];

        int sum = 1;
        for (int i = 1; i < rounds.length; i++) {
            int start = rounds[i - 1];
            int end = rounds[i];
            if (end > start) sum += end - start;
            else sum += n - start + end;
        }
        offset = sum % n == 0 ? n : sum % n;
        List<Integer> most_visited = new ArrayList<>();
        for (int i = 0; i < offset; i++) {
            most_visited.add(index);
            if (index == n) index = 1;
            else index++;
        }
        most_visited.sort(Integer::compareTo);
        return most_visited;
    }

    public static void main(String[] args) {
        MostVisitedSector_in_aCircularTrack main = new MostVisitedSector_in_aCircularTrack();
        System.out.println(main.mostVisited(4, new int[]{1, 3, 1, 2}));
        System.out.println(main.mostVisited(7, new int[]{1, 3, 5, 7}));
        System.out.println(main.mostVisited(2, new int[]{2, 1, 2, 1, 2, 1, 2, 1, 2}));
    }
}
