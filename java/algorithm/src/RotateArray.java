import java.util.ArrayDeque;
import java.util.Deque;

public class RotateArray {
    /**
     * Runtime: 3 ms, faster than 26.15% of Java online submissions for Rotate Array.
     * Memory Usage: 39.1 MB, less than 5.09% of Java online submissions for Rotate Array.
     */
    public void rotate(int[] nums, int k) {
        if (nums == null || nums.length <= 1) return;

        Deque<Integer> queue = new ArrayDeque<>();

        for (int i : nums) {
            queue.push(i);
        }

        while (k > 0) {
            queue.add(queue.pop());
            k--;
        }

        int i = nums.length - 1;
        while (!queue.isEmpty()) {
            nums[i] = queue.pop();
            i--;
        }
    }
}
