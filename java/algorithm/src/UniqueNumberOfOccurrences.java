import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class UniqueNumberOfOccurrences {
    /**
     * Runtime: 2 ms, faster than 59.15% of Java online submissions for Unique
     * Number of Occurrences. Memory Usage: 39.8 MB, less than 6.14% of Java online
     * submissions for Unique Number of Occurrences.
     */
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            int count = map.getOrDefault(i, 0);
            map.put(i, count + 1);
        }
        Set<Integer> set = new HashSet<>();
        set.addAll(map.values());
        return set.size() == map.size();
    }
}