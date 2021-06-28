package todo;

import java.util.Stack;

public class RemoveAllAdjacentDuplicatesInString {
    public String removeDuplicates(String s) {
        Stack<Character> stack = new Stack<>();
        char last_ch = 0;
        for (char ch : s.toCharArray()) {
            if (stack.isEmpty()) {
                stack.push(ch);
                last_ch = ch;
            } else {
                if (ch == stack.peek()) {
                    stack.pop();
                } else if (ch != last_ch) {
                    stack.push(ch);
                    last_ch = ch;
                }
            }
        }
        char[] arr = new char[stack.size()];
        for (int i = arr.length - 1; i >= 0; i--) {
            arr[i] = stack.pop();
        }
        return new String(arr);
    }

    public static void main(String[] args) {
        RemoveAllAdjacentDuplicatesInString main = new RemoveAllAdjacentDuplicatesInString();
        System.out.println(main.removeDuplicates("abbbabaaa").equals("ababa"));
    }
}
