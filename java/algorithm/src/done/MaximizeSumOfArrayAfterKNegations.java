package done;

import java.util.Arrays;

/**
 * 1005
 */
public class MaximizeSumOfArrayAfterKNegations {
    /**
     * Runtime: 13 ms, faster than 12.28% of Java online submissions for Maximize Sum Of Array After K Negations.
     * Memory Usage: 38.8 MB, less than 23.12% of Java online submissions for Maximize Sum Of Array After K Negations.
     */
    public int largestSumAfterKNegations(int[] nums, int k) {
        Arrays.sort(nums);

        int index = 0;
        while (k != 0) {
            if (nums[index] < 0) {
                nums[index] = -nums[index];
                k--;
                Arrays.sort(nums);
                index = 0;
            } else if (nums[index] == 0) {
                break;
            } else if (k % 2 == 0) {
                break;
            } else {
                nums[index] = -nums[index];
                k--;
                Arrays.sort(nums);
                index = 0;
            }
        }

        int sum = 0;
        for (int n : nums) sum += n;
        return sum;
    }
}
