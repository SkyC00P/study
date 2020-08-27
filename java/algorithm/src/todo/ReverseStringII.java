package todo;
import java.util.Stack;

public class ReverseStringII {
    public String reverseStr(String s, int k) {
        StringBuilder sb = new StringBuilder();

        Stack<Character> stack = new Stack<>();
        char[] chs = s.toCharArray();
        int i = 0, count = 0, len = s.length();
        while (i < len) {
            char ch = chs[i];
            count++;
            if (count < k) {
                stack.push(ch);
                i++;
            } else if (count == k) {
                stack.push(ch);
                insertAll(stack, sb);
                for (int j = 0; j < k; j++) {
                    i++;
                    if (i < len) {
                        sb.append(chs[i]);
                    }
                }
                count = 0;
            }
        }

        insertAll(stack, sb);
        return sb.toString();
    }

    private void insertAll(Stack<Character> stack, StringBuilder sb) {
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
    }

    public static void main(String[] args) {
        ReverseStringII main = new ReverseStringII();
        System.out.println("bacdfeg".equals(main.reverseStr("abcdefg", 2)));
    }
}