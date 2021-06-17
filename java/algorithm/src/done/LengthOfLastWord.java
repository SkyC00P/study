package done;

public class LengthOfLastWord {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Length of Last Word.
     * Memory Usage: 37.4 MB, less than 15.33% of Java online submissions for Length of Last Word.
     */
    public int lengthOfLastWord(String s) {
        if (s == null || s.isEmpty()) return 0;

        int fistChar = s.length() - 1;
        for (int i = fistChar; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                fistChar = i;
                break;
            }
        }

        int sum = 0;
        for (int i = fistChar; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                sum++;
            } else break;
        }
        return sum;
    }
}
