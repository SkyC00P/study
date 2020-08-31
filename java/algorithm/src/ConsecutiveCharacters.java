public class ConsecutiveCharacters {
    /**
     * Runtime: 5 ms, faster than 8.59% of Java online submissions for Consecutive
     * Characters. Memory Usage: 40 MB, less than 9.84% of Java online submissions
     * for Consecutive Characters.
     */
    public int maxPower(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        char[] chs = s.toCharArray();
        int max = 0;
        int count = 1;
        for (int i = 0; i < chs.length; i++) {
            int ch = chs[i];
            for (int j = i + 1; j < chs.length; j++) {
                if (chs[j] == ch) {
                    count++;
                } else {
                    i = j - 1;
                    break;
                }
            }
            if (count > max) {
                max = count;
            }
            count = 1;
        }
        return max;
    }
}