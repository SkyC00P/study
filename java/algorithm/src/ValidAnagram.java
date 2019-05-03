import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class ValidAnagram {
    /**
     * Runtime: 56 ms, faster than 5.03% of Java online submissions for Valid Anagram.
     * Memory Usage: 35.5 MB, less than 94.99% of Java online submissions for Valid Anagram.
     */
    public boolean isAnagram(String s, String t) {
        if (t.length() != s.length()) {
            return false;
        }

        Map<Character, Integer> smap = new HashMap<>();
        Map<Character, Integer> tmap = new HashMap<>();
        for (char ch : s.toCharArray()) {
            smap.merge(ch, 1, (oldV, defV) -> oldV + 1);
        }
        for (char ch : t.toCharArray()) {
            tmap.merge(ch, 1, (oldV, defV) -> oldV + 1);
        }

        for (char ch : s.toCharArray()) {
            int sum_s = smap.getOrDefault(ch, 0);
            int sum_t = tmap.getOrDefault(ch, 0);
            if (sum_s != sum_t) {
                return false;
            }
        }

        return true;
    }
}
