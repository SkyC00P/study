public class PowerOfThree {

    /**
     * Runtime: 11 ms, faster than 56.73% of Java online submissions for Power of Three.
     * Memory Usage: 35.7 MB, less than 99.67% of Java online submissions for Power of Three.
     */
    public boolean isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }
}
