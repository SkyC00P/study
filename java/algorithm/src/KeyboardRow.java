import java.util.*;

/**
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 */
public class KeyboardRow {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Keyboard Row.
     * Memory Usage: 37.6 MB, less than 30.00% of Java online submissions for Keyboard Row.
     */
    public String[] findWords(String[] words) {
        Set<Character> r1 = new HashSet<>();
        Set<Character> r2 = new HashSet<>();
        Set<Character> r3 = new HashSet<>();

        List<String> list = new ArrayList<>();
        for (char c : "qwertyuiopQWERTYUIOP".toCharArray()) {
            r1.add(c);
        }
        for (char c : "asdfghjklASDFGHJKL".toCharArray()) {
            r2.add(c);
        }
        for (char c : "zxcvbnmZXCVBNM".toCharArray()) {
            r3.add(c);
        }
        Loop:
        for (String s : words) {
            char ch = s.charAt(0);
            if (r1.contains(ch)) {
                for (int i = 1; i < s.length(); i++) {
                    if (!r1.contains(s.charAt(i))) {
                        continue Loop;
                    }
                }
                list.add(s);
            }
            if (r2.contains(ch)) {
                for (int i = 1; i < s.length(); i++) {
                    if (!r2.contains(s.charAt(i))) {
                        continue Loop;
                    }
                }
                list.add(s);
            }
            if (r3.contains(ch)) {
                for (int i = 1; i < s.length(); i++) {
                    if (!r3.contains(s.charAt(i))) {
                        continue Loop;
                    }
                }
                list.add(s);
            }
        }
        return list.toArray(new String[]{});
    }

    public static void main(String[] args) {
        KeyboardRow keyboardRow = new KeyboardRow();
        String[] arr = new String[]{"Hello", "Alaska", "Dad", "Peace"};
        System.out.println(Arrays.toString(keyboardRow.findWords(arr)));
    }
}
