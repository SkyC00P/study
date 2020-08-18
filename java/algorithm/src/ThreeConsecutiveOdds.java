public class ThreeConsecutiveOdds {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Three
     * Consecutive Odds. Memory Usage: 39.5 MB, less than 72.36% of Java online
     * submissions for Three Consecutive Odds.
     */
    public boolean threeConsecutiveOdds(int[] arr) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            int index = i;
            while (index < arr.length && isOdd(arr[index])) {
                index++;
                count++;
                if (count == 3)
                    return true;
            }
            i = index;
            count = 0;
        }
        return false;
    }

    private boolean isOdd(int n) {
        return (n & 1) == 1;
    }

    public static void main(String[] args) {
        ThreeConsecutiveOdds main = new ThreeConsecutiveOdds();
        // false
        System.out.println(main.threeConsecutiveOdds(new int[] { 2, 6, 4, 1 }));
        // true
        System.out.println(main.threeConsecutiveOdds(new int[] { 1, 2, 34, 3, 4, 5, 7, 23, 12 }));
        // false
        System.out.println(main.threeConsecutiveOdds(new int[] { 1, 2, 1, 1 }));
    }
}