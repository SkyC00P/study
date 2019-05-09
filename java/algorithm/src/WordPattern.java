import java.util.*;

/**
 * You may assume pattern contains only lowercase letters,
 * and str contains lowercase letters that may be separated by a single space.
 */
public class WordPattern {

    /**
     * Runtime: 1 ms, faster than 98.63% of Java online submissions for Word Pattern.
     * Memory Usage: 33.1 MB, less than 51.34% of Java online submissions for Word Pattern
     */
    public boolean wordPattern(String pattern, String str) {
        String[] arr_str = str.split(" ");
        if (arr_str.length != pattern.length()) {
            return false;
        }

        Map<Character, String> map = new HashMap<>();
        for (int i = 0, j = 0; i < arr_str.length; i++, j++) {
            char ch = pattern.charAt(i);
            String s = arr_str[j];

            if (!map.containsKey(ch)) {
                if (map.containsValue(s)) return false;
                map.put(ch, s);
            } else if (!map.get(ch).equals(s)) {
                return false;
            }

        }

        return true;
    }
}
