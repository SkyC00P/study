package done;

import java.util.HashMap;
import java.util.Map;

public class MostCommonWord {
    /**
     * Runtime: 4 ms, faster than 96.95% of Java online submissions for Most Common Word.
     * Memory Usage: 38.9 MB, less than 92.90% of Java online submissions for Most Common Word.
     */
    public String mostCommonWord(String paragraph, String[] banned) {
        Map<String, Integer> map = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (char ch : paragraph.toCharArray()) {
            switch (ch) {
                case ' ':
                case '!':
                case '?':
                case ',':
                case ';':
                case '.':
                case '\'':
                    if (sb.length() != 0) {
                        String word = sb.toString().toLowerCase();
                        int num = map.getOrDefault(word, 0);
                        map.put(word, num + 1);
                        sb = new StringBuilder();
                    }
                    break;
                default:
                    sb.append(ch);
            }
        }
        if (sb.length() != 0) {
            String word = sb.toString().toLowerCase();
            int num = map.getOrDefault(word, 0);
            map.put(word, num + 1);
        }

        for (String b : banned) {
            map.remove(b);
        }
        int max = 0;
        String max_str = "";
        for (String k : map.keySet()) {
            if (map.get(k) > max) {
                max = map.get(k);
                max_str = k;
            }
        }
        return max_str;
    }

    public static void main(String[] args) {
        // "a, a, a, a, b,b,b,c, c"
        //["a"]
        MostCommonWord main = new MostCommonWord();
        // "b"
        System.out.println(main.mostCommonWord("a, a, a, a, b,b,b,c, c", new String[]{"a"}));
    }
}
