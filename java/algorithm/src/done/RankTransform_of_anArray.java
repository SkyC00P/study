package done;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class RankTransform_of_anArray {
    Map<Integer, Integer> Ranks = new HashMap<>();

    /**
     * Runtime: 29 ms, faster than 68.10% of Java online submissions for Rank
     * Transform of an Array. Memory Usage: 56.9 MB, less than 60.21% of Java online
     * submissions for Rank Transform of an Array.
     */
    public int[] arrayRankTransform(int[] arr) {

        int[] ranks = new int[arr.length];
        initRanks(arr);
        for (int i = 0; i < arr.length; i++) {
            int rank = Ranks.get(arr[i]);
            ranks[i] = rank;
        }
        return ranks;
    }

    private void initRanks(int[] arr) {
        Ranks.clear();
        int[] cp = Arrays.copyOf(arr, arr.length);
        Arrays.sort(cp);
        int index = 0, rank = 0;
        while (index < arr.length) {
            int cur = cp[index];

            do {
                index++;
            } while (index < cp.length && cur == cp[index]);

            rank++;
            Ranks.put(cur, rank);
        }
    }
}
