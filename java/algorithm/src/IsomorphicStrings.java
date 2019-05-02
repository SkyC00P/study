import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class IsomorphicStrings {

    /**
     * Runtime: 14 ms, faster than 30.73% of Java online submissions for Isomorphic Strings.
     * Memory Usage: 39.8 MB, less than 5.09% of Java online submissions for Isomorphic Strings.
     */
    public boolean isIsomorphic(String s, String t) {
        StringBuilder sb = new StringBuilder();
        Map<Character, Character> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (map.containsKey(ch)) {
                sb.append(map.get(ch));
            } else {
                char parent_ch = (char) ('A' + map.size());
                map.put(ch, parent_ch);
                sb.append(parent_ch);
            }
        }

        String parent = sb.toString();
        map.clear();
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            if (map.containsKey(ch)) {
                if (parent.charAt(i) != map.get(ch)) {
                    return false;
                }
            } else {
                char parent_ch = (char) ('A' + map.size());
                if (parent.charAt(i) != parent_ch) {
                    return false;
                }
                map.put(ch, parent_ch);
            }
        }
        return true;
    }
}
