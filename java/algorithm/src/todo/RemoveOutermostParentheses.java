package todo;

import java.util.Stack;

/**
 * 1021
 */
public class RemoveOutermostParentheses {
    public String removeOuterParentheses(String s) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        Stack<Character> stack = new Stack<>();
        for (char ch : s.toCharArray()) {
            stack.push(ch);
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                if (count == 0) {
                    appendStr(stack, sb);
                }
            }
        }
        return sb.toString();
    }

    private void appendStr(Stack<Character> stack, StringBuilder sb) {
        stack.pop();
        while (!stack.isEmpty()) {
            sb.insert(0, stack.pop());
        }
        sb.deleteCharAt(0);
    }

    public static void main(String[] args) {
        RemoveOutermostParentheses main = new RemoveOutermostParentheses();
//        System.out.println(main.removeOuterParentheses("(()())(())"));
        // ()()()()(())
        System.out.println(main.removeOuterParentheses("(()())(())(()(()))"));
    }
}
