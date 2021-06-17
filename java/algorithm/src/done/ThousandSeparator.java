package done;

import java.util.Stack;

public class ThousandSeparator {
    /**
     * Runtime: 8 ms, faster than 37.06% of Java online submissions for Thousand
     * Separator. Memory Usage: 37.5 MB, less than 71.56% of Java online submissions
     * for Thousand Separator.
     */
    public String thousandSeparator(int n) {
        if (n < 1000)
            return n + "";
        Stack<Integer> stack = new Stack<>();
        int num = n;
        do {
            int j = num % 1000;
            stack.push(j);
            num = num / 1000;
        } while (num != 0);

        StringBuilder sb = new StringBuilder();
        sb.append(stack.pop());
        while (!stack.isEmpty()) {
            int i = stack.pop();
            String s = String.format("%03d", i);
            sb.append('.').append(s);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        ThousandSeparator main = new ThousandSeparator();
        System.out.println("1.234".equals(main.thousandSeparator(1234)));
        System.out.println("123.456.789".equals(main.thousandSeparator(123456789)));
        System.out.println("0".equals(main.thousandSeparator(0)));
        System.out.println("51.040".equals(main.thousandSeparator(51040)));
    }
}
