package done;

import java.util.Stack;

public class RomanToInteger {

    private int coverRoman(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        throw new IllegalArgumentException("c:" + c);
    }

    /**
     * Runtime: 8 ms, faster than 94.41% of Java online submissions for Roman to Integer.
     * Memory Usage: 39 MB, less than 24.61% of Java online submissions for Roman to Integer.
     */
    public int romanToInt(String s) {
        if (s.isEmpty()) return 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(coverRoman(s.charAt(0)));

        for (int i = 1; i < s.length(); i++) {
            int num = coverRoman(s.charAt(i));
            int top = stack.peek();

            if (top >= num) {
                stack.push(num);
            } else {
                Stack<Integer> stack1 = new Stack<>();
                stack1.push(stack.pop());
                stack1.push(num);
                for (; i < s.length() - 1; i++) {
                    int n = coverRoman(s.charAt(i + 1));
                    if (n <= stack1.peek()) {
                        break;
                    }
                    stack1.push(n);
                }
                int sum = stack1.pop();
                while (!stack1.empty()) {
                    sum -= stack1.pop();
                }
                stack.push(sum);
            }

        }

        int sum = stack.pop();
        while (!stack.empty()) {
            sum += stack.pop();
        }
        return sum;
    }

    public static void main(String[] args) {
        RomanToInteger solution = new RomanToInteger();
        System.out.println(solution.romanToInt("III") == 3);
        System.out.println(solution.romanToInt("IV") == 4);
        System.out.println(solution.romanToInt("IX") == 9);
        System.out.println(solution.romanToInt("LVIII") == 58);
        System.out.println(solution.romanToInt("MCMXCIV") == 1994);
    }
}
