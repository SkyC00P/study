package done;

import java.util.HashSet;
import java.util.Set;

public class DistributeCandies {
    /**
     * Runtime: 32 ms, faster than 77.25% of Java online submissions for Distribute Candies.
     * Memory Usage: 40.7 MB, less than 83.28% of Java online submissions for Distribute Candies.
     */
    public int distributeCandies(int[] candyType) {
        int max_eat = candyType.length / 2;
        Set<Integer> kinds = new HashSet<>();
        for (int t : candyType) {
            kinds.add(t);
        }
        return Math.min(max_eat, kinds.size());
    }
}
