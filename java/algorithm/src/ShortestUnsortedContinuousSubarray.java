import java.util.Arrays;

public class ShortestUnsortedContinuousSubarray {
    /**
     * Runtime: 6 ms, faster than 53.63% of Java online submissions for Shortest
     * Unsorted Continuous Subarray. Memory Usage: 40.5 MB, less than 86.17% of Java
     * online submissions for Shortest Unsorted Continuous Subarray.
     */
    public int findUnsortedSubarray(int[] nums) {
        if (nums.length <= 1)
            return 0;
        int[] arr = Arrays.copyOf(nums, nums.length);
        int left = -1;
        int right = -1;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != arr[i]) {
                left = i;
                break;
            }
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] != arr[i]) {
                right = i;
                break;
            }
        }
        return left == right ? 0 : right - left + 1;
    }
}
