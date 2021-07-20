package done;

import java.util.Arrays;

public class MaximumProductOfThreeNumbers {
    /**
     * Runtime: 9 ms, faster than 64.21% of Java online submissions for Maximum Product of Three Numbers.
     * Memory Usage: 40.8 MB, less than 22.97% of Java online submissions for Maximum Product of Three Numbers.
     */
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n1 = nums[nums.length - 1];
        int n2 = nums[nums.length - 2];
        int n3 = nums[nums.length - 3];
        if (nums.length == 3 || nums[0] >= 0 || n1 <= 0) return n1 * n2 * n3;
        if (n2 >= 0 && n3 >= 0) {
            int a = nums[0] * nums[1];
            int b = n2 * n3;
            return a > b ? a * n1 : b * n1;
        } else
            return nums[0] * nums[1] * n1;
    }

    public static void main(String[] args) {
        MaximumProductOfThreeNumbers main = new MaximumProductOfThreeNumbers();
        System.out.println(main.maximumProduct(new int[]{1, 2, 3, 4}));
        // [-100,-98,-1,2,3,4]
        System.out.println(main.maximumProduct(new int[]{-100, -98, -1, 2, 3, 4}));
    }
}
