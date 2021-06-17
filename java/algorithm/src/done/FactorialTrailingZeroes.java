package done;

import utils.MathUtils;

public class FactorialTrailingZeroes {
    public int trailingZeroes_1(int n) {
        int num = MathUtils.factorial_lambda(n);
        if(num == 0) return 0;
        int count = 0;
        while (num % 10 == 0) {
            count += 1;
            num /= 10;
        }
        return count;
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Factorial Trailing Zeroes.
     * Memory Usage: 32.3 MB, less than 100.00% of Java online submissions for Factorial Trailing Zeroes.
     */
    public int trailingZeroes(int n) {
        int r = 0;
        while (n > 0) {
            n /= 5;
            r += n;
        }
        return r;
    }
}
