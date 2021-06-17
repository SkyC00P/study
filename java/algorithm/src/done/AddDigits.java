package done;

/**
 * Could you do it without any loop/recursion in O(1) runtime?
 */
public class AddDigits {

    /**
     * Runtime: 1 ms, faster than 94.60% of Java online submissions for Add Digits.
     * Memory Usage: 32.3 MB, less than 100.00% of Java online submissions for Add Digits.
     */
    public int addDigits(int num) {
        int n = num;
        while (n >= 10) {
            int sum = 0;
            while (n != 0) {
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }
        return n;
    }

    /**
     * Runtime: 1 ms, faster than 94.60% of Java online submissions for Add Digits.
     * Memory Usage: 32.4 MB, less than 100.00% of Java online submissions for Add Digits.
     */
    public int addDigits1(int num) {
        return 1 + (num - 1) % 9;
    }
}
