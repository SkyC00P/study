package todo;

/**
 * 896
 */
public class MonotonicArray {
    public boolean isMonotonic(int[] nums) {
        if (nums.length < 3) return true;
        for (int i = 0; i + 2 < nums.length; i++) {
            boolean b1 = nums[i] >= nums[i + 1];
            boolean b2 = nums[i + 1] >= nums[i + 2];
            if (b1 != b2) return false;
        }
        return true;
    }
}
