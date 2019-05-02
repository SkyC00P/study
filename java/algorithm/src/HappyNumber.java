import java.util.*;

public class HappyNumber {

    /**
     * Runtime: 2 ms, faster than 51.09% of Java online submissions for Happy Number.
     * Memory Usage: 32.3 MB, less than 100.00% of Java online submissions for Happy Number.
     */
    public boolean isHappy(int n) {
        Stack<Integer> stack = new Stack<>();
        stack.push(n);
        while (!stack.isEmpty()) {
            int num = stack.peek();
            int sum = 0;
            while (num != 0) {
                sum += Math.pow(num % 10, 2);
                num /= 10;
            }
            if (sum == 1) return true;
            if (stack.contains(sum)) return false;
            stack.push(sum);
        }
        return false;
    }
}
