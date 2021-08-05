package done;

import java.util.Arrays;

public class SquaresOfASortedArray {
    /**
     * Runtime: 2 ms, faster than 61.07% of Java online submissions for Squares of a Sorted Array.
     * Memory Usage: 41.2 MB, less than 25.98% of Java online submissions for Squares of a Sorted Array.
     */
    public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] = (int) Math.pow(nums[i], 2);
        }
        Arrays.sort(nums);
        return nums;
    }
}
