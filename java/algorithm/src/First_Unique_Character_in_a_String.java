import java.util.HashMap;
import java.util.Map;

public class First_Unique_Character_in_a_String {
    /**
     * Runtime: 38 ms, faster than 40.66% of Java online submissions for First Unique Character in a String.
     * Memory Usage: 35.8 MB, less than 99.96% of Java online submissions for First Unique Character in a String.
     */
    public int firstUniqChar(String s) {
        char[] chs = s.toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        for (char ch : chs) {
            int count = map.getOrDefault(ch, 0);
            map.put(ch, count + 1);
        }

        for (int i = 0; i < chs.length; i++) {
            if (map.get(chs[i]) == 1) return i;
        }
        return -1;
    }
}
