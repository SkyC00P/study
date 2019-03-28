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
 * p = ".*
 * "
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
        StringBuilder list = new StringBuilder();
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

        if (p.startsWith(".*")) {
            return true;
        }

        Node head = new Node();
        Node cur = head;
        for (int i = 0; i < p.length(); i++) {
            char ch = p.charAt(i);
            if (ch == '.') {
                cur.next = new Node();
                cur.next.list.append('.');
                cur = cur.next;
                cur.type = TYPE_COMMA;
            } else if (ch == '*') {
                cur.next = new Node();
                cur.next.type = TYPE_ASTERISK;
                char lastCh = cur.list.charAt(cur.list.length() - 1);
                cur.list.deleteCharAt(cur.list.length() - 1);
                cur.next.list.append(lastCh);
                cur = cur.next;
            } else {
                if (cur.type != TYPE_FIX) {
                    cur.next = new Node();
                    cur.next.type = TYPE_FIX;
                    cur = cur.next;
                }
                cur.list.append(ch);
            }
        }

        Node node = head;
        int index = 0;
        final int len = s.length();
        while (node != null) {
            if (node.type == TYPE_FIX) {
                if (index + node.list.length() > len) {
                    return false;
                }
                String str = s.substring(index, index + node.list.length());
                if (!node.list.toString().equals(str)) {
                    return false;
                }
                index += node.list.length();
            } else if (node.type == TYPE_COMMA) {
                if (index + 1 > len) {
                    return false;
                }
                index += 1;
            } else if (node.type == TYPE_ASTERISK) {
                char ch = node.list.charAt(0);
                if (ch == '*') {
                    return false;
                }
                if (ch == '.') {
                    return true;
                }
                while (index < len && ch == s.charAt(index)) {
                    index++;
                }
            }

            node = node.next;
        }

        return index >= len;
    }

    public static void main(String[] args) {
        RegularExpressionMatching solution = new RegularExpressionMatching();
        System.out.println("false = " + solution.isMatch("aa", "a"));
        System.out.println("true = " + solution.isMatch("aa", "a*"));
        System.out.println("true = " + solution.isMatch("ab", ".*"));
        System.out.println("true = " + solution.isMatch("aab", "c*a*b"));
        System.out.println("false = " + solution.isMatch("mississippi", "mis*is*p*."));
    }
}
