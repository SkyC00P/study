package todo;

import java.util.Objects;

public class RotateString {
    /**
     * Runtime: 4 ms, faster than 12.30% of Java online submissions for Rotate String.
     * Memory Usage: 38.8 MB, less than 13.97% of Java online submissions for Rotate String.
     */
    public boolean rotateString(String s, String goal) {
        int len = s.length();
        do {
            if (Objects.equals(s, goal)) return true;
            s = s.substring(1) + s.charAt(0);
            len--;
        } while (len != 0);

        return false;
    }
}
