package done;

import java.util.Objects;
import java.util.Stack;

public class BaseballGame {
    /**
     * Runtime: 5 ms, faster than 17.56% of Java online submissions for Baseball Game.
     * Memory Usage: 39.3 MB, less than 6.44% of Java online submissions for Baseball Game.
     */
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<>();
        for (String op : ops) {
            if (Objects.equals(op, "C")) {
                Integer n = stack.pop();
            } else if (Objects.equals(op, "D")) {
                stack.push(stack.peek() * 2);
            } else if (Objects.equals(op, "+")) {
                Integer n1 = stack.pop();
                Integer n2 = stack.pop();
                stack.push(n2);
                stack.push(n1);
                stack.push(n1 + n2);
            } else {
                stack.push(Integer.parseInt(op));
            }
        }
        int sum = 0;
        while (!stack.isEmpty()) {
            sum += stack.pop();
        }
        return sum;
    }
}
