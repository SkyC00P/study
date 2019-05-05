public class UglyNumber {
    /**
     * Runtime: 1 ms, faster than 95.97% of Java online submissions for Ugly Number.
     * Memory Usage: 32.3 MB, less than 100.00% of Java online submissions for Ugly Number.
     */
    public boolean isUgly(int num) {
        if (num <= 0) return false;
        int n = num;
        while (true) {
            if (n % 5 == 0) {
                n /= 5;
                continue;
            }

            if (n % 3 == 0) {
                n /= 3;
                continue;
            }

            if (n % 2 == 0) {
                n /= 2;
                continue;
            }
            return Math.abs(n) == 1;
        }
    }

    /**
     * Runtime: 1 ms, faster than 95.97% of Java online submissions for Ugly Number.
     * Memory Usage: 32.5 MB, less than 99.44% of Java online submissions for Ugly Number.
     */
    public boolean isUgly1(int num) {
        for (int i = 2; i < 6 && num > 0; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
}
