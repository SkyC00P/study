package done;

import java.util.HashMap;
import java.util.Map;

public class TwoSumII_InputArrayIsSorted {
    /**
     * Runtime: 2 ms, faster than 29.91% of Java online submissions for Two Sum II - Input array is sorted.
     * Memory Usage: 38 MB, less than 61.47% of Java online submissions for Two Sum II - Input array is sorted
     */
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            Integer pairNum = map.get(target - numbers[i]);
            if (pairNum != null) return new int[]{pairNum + 1, i + 1};
            map.put(numbers[i], i);
        }
        return null;
    }
}
