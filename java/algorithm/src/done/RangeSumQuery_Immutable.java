package done;

import java.util.HashMap;
import java.util.Map;

public class RangeSumQuery_Immutable {
    /**
     * Runtime: 235 ms, faster than 20.34% of Java online submissions for Range Sum Query - Immutable.
     * Memory Usage: 60 MB, less than 19.70% of Java online submissions for Range Sum Query - Immutable.
     */
    public static class NumArray {
        private int[] nums;

        public NumArray(int[] nums) {
            this.nums = nums;
        }

        public int sumRange(int i, int j) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            return sum;
        }
    }

    // 动态规划？
    public static class NumArray1 {
        private int[] nums;
        private Map<String, Integer> map = new HashMap<>();

        public NumArray1(int[] nums) {
            this.nums = nums;
        }

        public int sumRange(int i, int j) {
            if (i == j) {
                map.put(i + "", nums[i]);
                return nums[i];
            }
            if (map.containsKey(i + "" + j)) {
                return map.get(i + "" + j);
            } else {
                int sum = sumRange(i, j - 1) + nums[j];
                map.put(i + "" + j, sum);
                return sum;
            }
        }
    }
}
