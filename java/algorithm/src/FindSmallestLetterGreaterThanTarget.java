public class FindSmallestLetterGreaterThanTarget {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Find
     * Smallest Letter Greater Than Target. Memory Usage: 39 MB, less than 100.00%
     * of Java online submissions for Find Smallest Letter Greater Than Target.
     */
    public char nextGreatestLetter(char[] letters, char target) {
        char ch = letters[0];
        int min = Integer.MAX_VALUE;
        int len = target - 'a';
        for (int i = 0; i < letters.length; i++) {
            int n = letters[i] - 'a';
            if (n > len) {
                int old = min;
                min = Math.min(min, i);
                if (old != min) {
                    ch = letters[i];
                }
            }
        }
        return ch;
    }
}
