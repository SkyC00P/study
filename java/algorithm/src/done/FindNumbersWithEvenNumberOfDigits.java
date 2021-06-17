package done;

public class FindNumbersWithEvenNumberOfDigits {
    /**
     * Runtime: 10 ms, faster than 5.15% of Java online submissions for Find Numbers
     * with Even Number of Digits. Memory Usage: 39.4 MB, less than 48.70% of Java
     * online submissions for Find Numbers with Even Number of Digits.
     */
    public int findNumbers(int[] nums) {
        int event = 0;
        for (int i : nums) {
            String s = i + "";
            if ((s.length() & 1) == 0) {
                event++;
            }
        }
        return event;
    }
}
