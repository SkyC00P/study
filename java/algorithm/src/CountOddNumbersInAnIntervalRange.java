public class CountOddNumbersInAnIntervalRange {
    /**
     * Time Limit Exceeded
     */
    public int countOdds_fail(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if ((i & 1) == 1) {
                count++;
            }
        }
        return count;
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Count Odd Numbers in an Interval Range.
     * Memory Usage: 36.6 MB, less than 100.00% of Java online submissions for Count Odd Numbers in an Interval Range.
     */
    public int countOdds(int low, int high) {
        int n = high - low;
        boolean odd = (low & 1) == 1;
        if ((n & 1) == 0) {
            return n / 2 + (odd ? 1 : 0);
        } else {
            boolean h_odd = (high & 1) == 1;
            int i = (odd ? 1 : 0);
            return h_odd ? (n + 1) / 2 + i : (n - 1) / 2 + i;
        }
    }

    public static void main(String[] args) {
        CountOddNumbersInAnIntervalRange main = new CountOddNumbersInAnIntervalRange();
        // 4,7  5 7
        // 5,8  6,7,8
        System.out.println(3 == main.countOdds(3, 7));
        System.out.println(1 == main.countOdds(8, 10));
        System.out.println(0 == main.countOdds(0,0));
        System.out.println(1 == main.countOdds(1,1));
        System.out.println(0 == main.countOdds(2,2));
    }
}
