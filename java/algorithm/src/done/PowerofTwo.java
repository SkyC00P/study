package done;

public class PowerofTwo {
    /**
     * Runtime: 1 ms, faster than 93.11% of Java online submissions for Power of Two.
     * Memory Usage: 32.3 MB, less than 100.00% of Java online submissions for Power of Two.
     */
    public boolean isPowerOfTwo(int n) {
        long num = 1;
        while (n > num) {
            num = num << 1;
        }
        return n == num;
    }
}
