package done;

import java.util.HashMap;
import java.util.Map;

public class LongestHarmoniousSubsequence {

    /**
     * Runtime: 17 ms, faster than 60.27% of Java online submissions for Longest Harmonious Subsequence.
     * Memory Usage: 40.1 MB, less than 60.64% of Java online submissions for Longest Harmonious Subsequence.
     */
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer count = map.getOrDefault(nums[i], 0);
            count++;
            map.put(nums[i], count);
        }
        int max = 0;
        for (Integer k : map.keySet()) {
            Integer count = map.get(k);
            Integer _min_count = map.get(k - 1);
            Integer _max_count = map.get(k + 1);
            if (_min_count == null && _max_count == null) continue;
            if (_max_count != null) {
                int _max = count + _max_count;
                if (_max > max) max = _max;
            }
            if (_min_count != null) {
                int _max = count + _min_count;
                if (_max > max) max = _max;
            }
        }
        return max;
    }
}
