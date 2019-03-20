/**
 * Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
 * Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
 * and interprets them as a numerical value.
 * <p>
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 * <p>
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace characters,
 * no conversion is performed.
 * <p>
 * If no valid conversion could be performed, a zero value is returned.
 * <p>
 * Note:
 * 1.  Only the space character ' ' is considered as whitespace character.
 * 2.  Assume we are dealing with an environment which could only store integers within the 32-bit signed integer
 * range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1)
 * or INT_MIN (−2^31) is returned.
 * <p>
 * Example 1:
 * Input: "42"
 * Output: 42
 * <p>
 * Example 2:
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus sign.
 * Then take as many numerical digits as possible, which gets 42.
 * <p>
 * Example 3:
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 * <p>
 * Example 4:
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a numerical
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * <p>
 * Example 5:
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 */
public class StringtoInteger {

    /**
     * Runtime: 16 ms, faster than 80.75% of Java online submissions for String to Integer (atoi).
     * Memory Usage: 38.5 MB, less than 21.25% of Java online submissions for String to Integer (atoi).
     */
    public int myAtoi(String str) {
        StringBuilder sb = new StringBuilder();
        String s = str.trim();
        if (s.isEmpty()) {
            return 0;
        }
        char ch = s.charAt(0);
        int index = 0;
        if (ch == '-' || ch == '+') {
            index = 1;
        } else if (getNum(ch) < 0) {
            return 0;
        }
        for (; index < s.length(); index++) {
            ch = s.charAt(index);
            if (getNum(ch) >= 0) {
                sb.append(ch);
            } else break;
        }

        double num = 0;
        for (int i = 0; i < sb.length(); i++) {
            num += getNum(sb.charAt(i)) * Math.pow(10, sb.length() - i - 1);
            if (num > Integer.MAX_VALUE) {
                return s.charAt(0) == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
        }
        return (int) (s.charAt(0) == '-' ? -num : num);
    }

    private int getNum(char ch) {
        switch (ch) {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            case '0':
                return 0;
        }
        return -1;
    }

    public static void main(String[] args) {
        StringtoInteger solution = new StringtoInteger();
        System.out.println(42 == solution.myAtoi("42"));
        System.out.println(-42 == solution.myAtoi("   -42"));
        System.out.println(4193 == solution.myAtoi("4193 with words"));
        System.out.println(0 == solution.myAtoi("words and 987"));
        System.out.println(-2147483648 == solution.myAtoi("-91283472332"));
        System.out.println(-2147483648 == solution.myAtoi("-2147483648"));
    }
}
