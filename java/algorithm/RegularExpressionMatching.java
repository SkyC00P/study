import java.util.ArrayList;
import java.util.List;

/**
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * <p>
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * <p>
 * The matching should cover the entire input string (not partial).
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 * <p>
 * Example 1:
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * <p>
 * Example 2:
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * <p>
 * Example 3:
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * <p>
 * Example 4:
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 * <p>
 * Example 5:
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 */
public class RegularExpressionMatching {

    class Node {
        List<Character> list = new ArrayList<>();
        int type = TYPE_FIX;
        Node next;
    }

    private static final int TYPE_FIX = 1;
    private static final int TYPE_ASTERISK = 2;
    private static final int TYPE_COMMA = 3;

    public boolean isMatch(String s, String p) {
        if (p == null || s == null) {
            return false;
        }

        if (p.isEmpty()) {
            return s.isEmpty();
        }

        Node head = new Node();
        Node cur = head;
        for (int i = 0; i < p.length(); i++) {
            char ch = p.charAt(i);
            if (ch == '.') {
                cur.next = new Node();
                cur.list.add('.');
                cur = cur.next;
                cur.type = TYPE_COMMA;
            } else if (ch == '*') {
                cur.next = new Node();
                cur.next.type = TYPE_ASTERISK;
                char lastCh = cur.list.remove(cur.list.size() - 1);
                cur.next.list.add(lastCh);
                cur = cur.next;
            } else {
                if (cur.type != TYPE_FIX) {
                    cur.next = new Node();
                    cur.next.type = TYPE_FIX;
                    cur = cur.next;
                }
                cur.list.add(ch);
            }
        }

    }

    public static void main(String[] args) {

    }
}
