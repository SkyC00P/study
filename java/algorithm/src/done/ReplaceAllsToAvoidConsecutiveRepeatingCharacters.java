package done;

/**
 * 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
 */
public class ReplaceAllsToAvoidConsecutiveRepeatingCharacters {
    /**
     * Runtime: 1 ms, faster than 48.57% of Java online submissions for Replace All
     * ?'s to Avoid Consecutive Repeating Characters. Memory Usage: 39.4 MB, less
     * than 25.96% of Java online submissions for Replace All ?'s to Avoid
     * Consecutive Repeating Characters.
     */
    public String modifyString(String s) {
        char[] chs = s.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            if (chs[i] == '?') {
                chs[i] = replace(i, chs);
            }
        }
        return new String(chs);
    }

    private char replace(int i, char[] chs) {
        int left = i - 1;
        int right = i + 1;
        char ch = 'a';
        while (ch <= 'z') {
            if (right < chs.length) {
                char r = chs[right];
                if (r != '?' && r == ch) {
                    ch += 1;
                    continue;
                }
            }
            if (left >= 0) {
                char l = chs[left];
                if (l == ch) {
                    ch += 1;
                    continue;
                }
            }
            break;
        }
        return ch;
    }

    public static void main(String[] args) {
        ReplaceAllsToAvoidConsecutiveRepeatingCharacters main = new ReplaceAllsToAvoidConsecutiveRepeatingCharacters();
        System.out.println(main.modifyString("?zs"));
    }
}
