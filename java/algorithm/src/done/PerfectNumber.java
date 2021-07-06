package done;

public class PerfectNumber {
    /**
     * Runtime: 2862 ms, faster than 5.30% of Java online submissions for Perfect Number.
     * Memory Usage: 35.8 MB, less than 37.55% of Java online submissions for Perfect Number.
     */
    public boolean checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }

        int sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return num == sum;
    }
}
