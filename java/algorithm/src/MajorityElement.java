import java.util.HashMap;
import java.util.Map;

public class MajorityElement {

    /**
     * Runtime: 12 ms, faster than 38.53% of Java online submissions for Majority Element.
     * Memory Usage: 41.2 MB, less than 29.12% of Java online submissions for Majority Element.
     */
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }

        int num = nums[0];
        int majority = map.get(nums[0]);
        for (Integer i : map.keySet()) {
            int max = map.get(i);
            if (max > majority) {
                majority = max;
                num = i;
            }
        }
        return num;
    }
}
