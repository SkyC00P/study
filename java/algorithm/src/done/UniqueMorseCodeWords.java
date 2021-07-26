package done;

import java.util.HashSet;
import java.util.Set;

public class UniqueMorseCodeWords {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Unique Morse Code Words.
     * Memory Usage: 37 MB, less than 64.46% of Java online submissions for Unique Morse Code Words.
     */
    public int uniqueMorseRepresentations(String[] words) {
        Set<String> uc = new HashSet<>();
        String[] chs = new String[]{
                ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        for (String s : words) {
            StringBuilder sb = new StringBuilder();
            for (char ch : s.toCharArray()) {
                sb.append(chs[ch - 'a']);
            }
            uc.add(sb.toString());
        }
        return uc.size();
    }
}
