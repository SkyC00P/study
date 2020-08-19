import java.util.HashMap;
import java.util.Map;

public class FindWordsThatCanBeFormedByCharacters {
    /**
     * Runtime: 56 ms, faster than 18.29% of Java online submissions for Find Words
     * That Can Be Formed by Characters. Memory Usage: 39.9 MB, less than 78.79% of
     * Java online submissions for Find Words That Can Be Formed by Characters.
     */
    public int countCharacters(String[] words, String chars) {
        int len = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (char ch : chars.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        for (String word : words) {
            if (isGoodStr(word, map)) {
                len += word.length();
            }
        }
        return len;
    }

    private boolean isGoodStr(String word, Map<Character, Integer> chs) {
        Map<Character, Integer> map = new HashMap<>();
        for (char ch : word.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        for (char ch : word.toCharArray()) {
            int count = map.get(ch);
            int chs_count = chs.getOrDefault(ch, 0);
            if (chs_count - count < 0) {
                return false;
            }
        }
        return true;
    }
}