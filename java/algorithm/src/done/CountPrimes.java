package done;

public class CountPrimes {
    /**
     * Runtime: 492 ms, faster than 14.99% of Java online submissions for Count Primes.
     * Memory Usage: 31.8 MB, less than 100.00% of Java online submissions for Count Primes.
     */
    public int countPrimes(int n) {
        int count = 0;

        while (n > 1) {
            n--;
            if (n != 2 && (n & 1) == 0) {
                continue;
            }
            if (isPrimes(n)) {
                count++;
            }
        }

        return count;
    }

    private boolean isPrimes(int n) {
        if (n <= 3) {
            return n > 1;
        }
        int sqrt = (int) Math.sqrt(n);
        for (int i = 2; i <= sqrt; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
