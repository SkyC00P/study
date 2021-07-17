package done;

import java.util.Arrays;

public class ArrayPartition_I {
    /**
     * Runtime: 10 ms, faster than 96.63% of Java online submissions for Array Partition I.
     * Memory Usage: 40.8 MB, less than 80.80% of Java online submissions for Array Partition I.
     */
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int max = 0;
        for (int i = 0; i < nums.length - 1; i += 2) {
            max += nums[i];
        }
        return max;
    }
}
