package done;

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

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Ransom Note.
     * Memory Usage: 36.8 MB, less than 99.55% of Java online submissions for Ransom Note.
     */
    public boolean canConstruct1(String ransomNote, String magazine) {
        if (magazine == null || magazine.isEmpty()) return ransomNote == null || ransomNote.isEmpty();
        int len = magazine.length();
        char[] chars = magazine.toCharArray();

        for (char ch : ransomNote.toCharArray()) {
            int oldLen = len;
            for (int i = 0; i < len; i++) {
                if (ch == chars[i]) {
                    chars[i] = chars[--len];
                    break;
                }
            }
            if (oldLen == len) return false;
        }
        return true;
    }
}
