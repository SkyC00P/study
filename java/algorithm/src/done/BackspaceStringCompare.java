package done;

import java.util.Stack;

public class BackspaceStringCompare {
    /**
     * Runtime: 1 ms, faster than 69.34% of Java online submissions for Backspace String Compare.
     * Memory Usage: 36.9 MB, less than 90.87% of Java online submissions for Backspace String Compare.
     */
    public boolean backspaceCompare(String s, String t) {
        Stack<Character> s1 = new Stack<>();
        Stack<Character> s2 = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == '#') {
                if (!s1.isEmpty()) s1.pop();
            } else {
                s1.push(ch);
            }
        }

        for (char ch : t.toCharArray()) {
            if (ch == '#') {
                if (!s2.isEmpty()) s2.pop();
            } else {
                s2.push(ch);
            }
        }

        if (s1.size() != s2.size()) return false;
        while (!s1.isEmpty()) {
            if (s1.pop() != s2.pop()) return false;
        }
        return true;
    }
}
