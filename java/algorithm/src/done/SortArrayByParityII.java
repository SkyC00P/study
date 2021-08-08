package done;

import java.util.Stack;

/**
 * 922
 */
public class SortArrayByParityII {
    /**
     * Runtime: 7 ms, faster than 12.64% of Java online submissions for Sort Array By Parity II.
     * Memory Usage: 44.1 MB, less than 15.82% of Java online submissions for Sort Array By Parity II.
     */
    public int[] sortArrayByParityII(int[] nums) {
        Stack<Integer> odds = new Stack<>();
        Stack<Integer> evens = new Stack<>();

        for (int n : nums) {
            if (n % 2 == 0) {
                evens.add(n);
            } else {
                odds.add(n);
            }
        }
        boolean odd = false;
        for (int i = 0; i < nums.length; i++) {
            if (odd) {
                nums[i] = odds.pop();
                odd = false;
            } else {
                nums[i] = evens.pop();
                odd = true;
            }
        }
        return nums;
    }
}
