import java.util.Arrays;
import java.util.Stack;

public class Number_of_Segments_in_a_String {
    /**
     * Runtime: 1 ms, faster than 36.95% of Java online submissions for Number of Segments in a String.
     * Memory Usage: 33.8 MB, less than 99.54% of Java online submissions for Number of Segments in a String.
     */
    public int countSegments(String s) {
        if (s == null || s.isEmpty()) return 0;
        Stack<Character> stack = new Stack<>();
        int size = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch != ' ') {
                stack.push(ch);
                continue;
            }
            if (!stack.isEmpty() && stack.peek() != ' ') {
                size++;
            }
            stack.push(' ');
        }

        return stack.peek() == ' ' ? size : size + 1;
    }

    public static void main(String[] args) {
        Number_of_Segments_in_a_String test = new Number_of_Segments_in_a_String();
        System.out.println(test.countSegments(", , , ,        a, eaefa"));
    }
}
