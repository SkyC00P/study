import java.util.Arrays;

public class MaximumProductOfTwoElementsInAnArray {
    /**
     * Runtime: 2 ms, faster than 31.15% of Java online submissions for Maximum
     * Product of Two Elements in an Array. Memory Usage: 38.6 MB, less than 99.53%
     * of Java online submissions for Maximum Product of Two Elements in an Array.
     */
    public int maxProduct(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        return (nums[len - 1] - 1) * (nums[len - 2] - 1);
    }
}