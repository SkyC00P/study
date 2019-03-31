import java.util.Stack;

public class ValidParentheses {

    /**
     * Runtime: 2 ms, faster than 97.27% of Java online submissions for Valid Parentheses.
     * Memory Usage: 35.7 MB, less than 36.72% of Java online submissions for Valid Parentheses.
     */
    public boolean isValid(String s) {
        if (s == null || s.isEmpty()) return true;
        char[] chs = s.toCharArray();

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < chs.length; i++) {
            if (isleft(chs[i])) {
                stack.push(chs[i]);
                continue;
            }

            if (stack.isEmpty() || !ismapping(stack.peek(), chs[i])) {
                return false;
            }
            stack.pop();
        }
        return stack.isEmpty();
    }

    private boolean ismapping(char lch, char rch) {
        switch (lch) {
            case '(':
                return rch == ')';
            case '[':
                return rch == ']';
            case '{':
                return rch == '}';
        }
        return false;
    }

    private boolean isleft(char ch) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        ValidParentheses solotion = new ValidParentheses();
        System.out.println(solotion.isValid("()"));
        System.out.println(solotion.isValid("()[]{}"));
        System.out.println(!solotion.isValid("(]"));
        System.out.println(!solotion.isValid("([)]"));
        System.out.println(solotion.isValid("{[]}"));
        System.out.println(!solotion.isValid("[])"));
    }
}
