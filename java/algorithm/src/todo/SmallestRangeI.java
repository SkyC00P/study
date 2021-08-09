package todo;

import java.util.Arrays;

/**
 * 908
 * 数学问题
 */
public class SmallestRangeI {
    public int smallestRangeI(int[] nums, int k) {
        int avg = 0;
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        avg = sum / nums.length;
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            int diff = Math.abs(n - avg);
            nums[i] = n > avg ? n - Math.min(diff, k) : n + Math.min(diff, k);
        }
        Arrays.sort(nums);
        return nums[nums.length - 1] - nums[0];
    }

    public static void main(String[] args) {
        System.out.println(5/3);
    }
}
