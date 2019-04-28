import java.util.Stack;

public class ExcelSheetColumnTitle {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Excel Sheet Column Title.
     * Memory Usage: 35.3 MB, less than 89.05% of Java online submissions for Excel Sheet Column Title.
     */
    public String convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(--n / 26) + (char) ('A' + (n % 26));
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Excel Sheet Column Title.
     * Memory Usage: 35.5 MB, less than 14.93% of Java online submissions for Excel Sheet Column Title.
     */
    public String convertToTitle_1(int n) {
        Stack<Character> stack = new Stack<>();
        int num = n;
        while (num != 0) {
            num--;
            stack.push((char) ('A' + (num % 26)));
            num = num / 26;
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        return sb.toString();
    }
}
