package done;

import java.util.Stack;

public class SplitAString_inBalancedStrings {

    /**
     * Runtime: 1 ms, faster than 37.69% of Java online submissions for Split a
     * String in Balanced Strings. Memory Usage: 37.4 MB, less than 19.66% of Java
     * online submissions for Split a String in Balanced Strings.
     */
    public int balancedStringSplit(String s) {
        Stack<Character> stack = new Stack<>();
        int max = 0, index = 0;
        while (true) {
            if (index == s.length()) {
                break;
            }
            char ch = s.charAt(index);
            if (stack.isEmpty()) {
                stack.push(ch);
                max += 1;
                index += 1;
                continue;
            }

            while (!stack.isEmpty()) {
                char top_ch = stack.peek();
                if (top_ch == ch) {
                    stack.push(ch);
                    index += 1;
                    break;
                } else {
                    stack.pop();
                    index++;
                    if (index != s.length()) {
                        ch = s.charAt(index);
                    }
                }
            }
        }

        return max;
    }

    public static void main(String[] args) {
        SplitAString_inBalancedStrings main = new SplitAString_inBalancedStrings();
        System.out.println(main.balancedStringSplit("RLRRLLRLRL"));
        System.out.println(main.balancedStringSplit("RLLLLRRRLR"));
        System.out.println(main.balancedStringSplit("LLLLRRRR"));
        System.out.println(main.balancedStringSplit("RLRRRLLRLL"));

    }
}
