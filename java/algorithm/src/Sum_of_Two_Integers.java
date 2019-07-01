/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 */
public class Sum_of_Two_Integers {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Sum of Two Integers.
     * Memory Usage: 32.3 MB, less than 42.25% of Java online submissions for Sum of Two Integers
     */
    public int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;

        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }

        return a;
    }
}
