public class MaximumSubarray {

    /**
     * 暴力求解
     * Runtime: 45 ms, faster than 6.99% of Java online submissions for Maximum Subarray.
     * Memory Usage: 39.6 MB, less than 39.12% of Java online submissions for Maximum Subarray.
     */
    public int maxSubArray(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int max = nums[0];
        for (int i = 0; i < nums.length; i++) {
            int sum = nums[i];
            if (sum > max) {
                max = sum;
            }
            for (int j = i + 1; j < nums.length; j++) {
                sum += nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }

}
