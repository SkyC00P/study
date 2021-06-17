package done;

import java.util.HashMap;
import java.util.Map;

public class ShortestCompletingWord {

    static class Data {
        int min = Integer.MAX_VALUE;
        String word;
    }

    /**
     * Runtime: 8 ms, faster than 32.62% of Java online submissions for Shortest Completing Word.
     * Memory Usage: 39.9 MB, less than 18.29% of Java online submissions for Shortest Completing Word.
     */
    public String shortestCompletingWord(String licensePlate, String[] words) {
        Map<Character, Integer> map = countCompletingWord(licensePlate);
        Data data = new Data();
        for (String word : words) {
            Map<Character, Integer> _map = countCompletingWord(word);
            if (isCompletingWord(map, _map) && data.min > word.length()) {
                data.min = word.length();
                data.word = word;
            }
        }
        return data.word;
    }

    private boolean isCompletingWord(Map<Character, Integer> licensePlate, Map<Character, Integer> m) {
        for (char ch : licensePlate.keySet()) {
            int c1 = licensePlate.getOrDefault(ch, 0);
            int c2 = m.getOrDefault(ch, 0);
            if (c2 < c1) return false;
        }
        return true;
    }

    private Map<Character, Integer> countCompletingWord(String word) {
        Map<Character, Integer> map = new HashMap<>();
        for (char ch : word.toCharArray()) {
            char _ch = Character.toLowerCase(ch);
            if (Character.isDigit(ch) || Character.isWhitespace(ch)) continue;
            Integer count = map.getOrDefault(_ch, 0) + 1;
            map.put(_ch, count);
        }
        return map;
    }
}
