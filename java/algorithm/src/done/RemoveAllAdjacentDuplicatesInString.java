package done;

import java.util.Stack;

public class RemoveAllAdjacentDuplicatesInString {
    /**
     * Runtime: 14 ms
     * Memory Usage: 39.3 MB
     */
    public String removeDuplicates(String s) {
        Stack<Character> stack = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (stack.isEmpty() || ch != stack.peek()) {
                stack.push(ch);
            } else {
                stack.pop();
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
        System.out.println(main.removeDuplicates("abbbabaaa"));
        System.out.println(main.removeDuplicates("abbbabaaa").equals("ababa"));
        System.out.println(main.removeDuplicates("abbaca")); //ca
    }
}
