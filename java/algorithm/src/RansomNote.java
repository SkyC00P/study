import java.util.HashMap;
import java.util.Map;

public class RansomNote {
    /**
     * Runtime: 24 ms, faster than 26.89% of Java online submissions for Ransom Note.
     * Memory Usage: 35.9 MB, less than 99.95% of Java online submissions for Ransom Note.
     */
    public boolean canConstruct(String ransomNote, String magazine) {

        Map<Character, Integer> chars = new HashMap<>();
        for (char ch : magazine.toCharArray()) {
            int count = chars.getOrDefault(ch, 0);
            chars.put(ch, count + 1);
        }

        for (char c : ransomNote.toCharArray()) {
            int count = chars.getOrDefault(c, 0);
            if (count == 0) return false;
            chars.put(c, count - 1);
        }
        return true;
    }
}
