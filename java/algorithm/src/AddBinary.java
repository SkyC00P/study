import java.util.Stack;

public class AddBinary {
    /**
     * Runtime: 5 ms, faster than 7.57% of Java online submissions for Add Binary.
     * Memory Usage: 37.1 MB, less than 31.95% of Java online submissions for Add Binary
     */
    public String addBinary(String a, String b) {
        Stack<Character> stack_a = new Stack<>();
        Stack<Character> stack_b = new Stack<>();
        Stack<Character> stack_c = new Stack<>();

        for (char ch : a.toCharArray()) {
            stack_a.push(ch);
        }
        for (char ch : b.toCharArray()) {
            stack_b.push(ch);
        }

        int carry_bit = 0;
        while (!stack_a.isEmpty() || !stack_b.isEmpty()) {
            char ch_a = '0';
            if (!stack_a.isEmpty()) {
                ch_a = stack_a.pop();
            }
            char ch_b = '0';
            if (!stack_b.isEmpty()) {
                ch_b = stack_b.pop();
            }
            if (ch_a == ch_b) {
                if (ch_a == '0') {
                    if (carry_bit == 1) {
                        stack_c.push('1');
                        carry_bit = 0;
                    } else {
                        stack_c.push('0');
                    }
                } else {
                    if (carry_bit == 1) {
                        stack_c.push('1');
                    } else {
                        stack_c.push('0');
                    }
                    carry_bit = 1;
                }
            } else {
                if (carry_bit == 0) {
                    stack_c.push('1');
                } else {
                    stack_c.push('0');
                    carry_bit = 1;
                }
            }
        }

        if(carry_bit == 1) stack_c.push('1');
        StringBuilder sb = new StringBuilder();
        while(!stack_c.isEmpty()){
            sb.append(stack_c.pop());
        }
        return sb.toString();
    }
}
