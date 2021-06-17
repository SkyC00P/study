package done;

import java.util.HashSet;
import java.util.Set;

public class Jewels_andStones {
    /**
     * Runtime: 1 ms, faster than 83.07% of Java online submissions for Jewels and
     * Stones. Memory Usage: 37.8 MB, less than 79.54% of Java online submissions
     * for Jewels and Stones.
     *
     * @return
     */
    public int numJewelsInStones(String J, String S) {
        Set<Character> j_set = new HashSet<>();
        for (char ch : J.toCharArray()) {
            j_set.add(ch);
        }
        int max = 0;
        for (char ch : S.toCharArray()) {
            if (j_set.contains(ch)) {
                max += 1;
            }
        }
        return max;
    }
}
