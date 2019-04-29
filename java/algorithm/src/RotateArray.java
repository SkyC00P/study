import java.util.Stack;

public class RotateArray {
    public void rotate(int[] nums, int k) {
        if (nums == null || nums.length <= 1) return;

        Stack<Integer> stack = new Stack<>();
        for (int i = nums.length - 1 - k; i >= 0; i--) {
            stack.push(nums[i]);
        }
        for (int i = nums.length - 1, j = k; j > 0; i--, j--) {
            stack.push(nums[i]);
        }

        int i = 0;
        while (!stack.isEmpty()) {
           nums[i] = stack.pop();
           i++;
        }

    }
}
