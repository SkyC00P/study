package done;

public class RunningSum_of_1dArray {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Running Sum
     * of 1d Array. Memory Usage: 40.4 MB, less than 30.44% of Java online
     * submissions for Running Sum of 1d Array.
     */
    public int[] runningSum(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum = nums[i] + sum;
            nums[i] = sum;
        }
        return nums;
    }
}
