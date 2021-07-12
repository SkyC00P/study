package done;

import java.util.Stack;

public class ReverseWordsInAString_III {
    /**
     * Runtime: 39 ms, faster than 10.79% of Java online submissions for Reverse Words in a String III.
     * Memory Usage: 62.6 MB, less than 5.04% of Java online submissions for Reverse Words in a String III.
     */
    public String reverseWords(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == ' ') {
                popAll(stack, sb);
                sb.append(' ');
            } else {
                stack.push(ch);
            }
        }
        popAll(stack, sb);
        return sb.toString();
    }

    private void popAll(Stack<Character> stack, StringBuilder sb) {
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
    }
}
