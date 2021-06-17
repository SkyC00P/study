package done;

/**
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * <p>
 * '.' Matches any single character. '*' Matches zero or more of the preceding
 * element.
 * <p>
 * The matching should cover the entire input string (not partial). Note: s
 * could be empty and contains only lowercase letters a-z. p could be empty and
 * contains only lowercase letters a-z, and characters like . or *.
 * <p>
 * Example 1: Input: s = "aa" p = "a" Output: false Explanation: "a" does not
 * match the entire string "aa".
 * <p>
 * Example 2: Input: s = "aa" p = "a*" Output: true Explanation: '*' means zero
 * or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it
 * becomes "aa".
 * <p>
 * Example 3: Input: s = "ab" p = ".* " Output: true Explanation: ".*" means
 * "zero or more (*) of any character (.)".
 * <p>
 * Example 4: Input: s = "aab" p = "c*a*b" Output: true Explanation: c can be
 * repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 * <p>
 * Example 5: Input: s = "mississippi" p = "mis*is*p*." Output: false
 */
public class RegularExpressionMatching {

    /**
     * Runtime: 57 ms, faster than 27.85% of Java online submissions for Regular Expression Matching.
     * Memory Usage: 42 MB, less than 19.31% of Java online submissions for Regular Expression Matching
     */
    public boolean isMatch(String s, String p) {
        if (p == null || s == null) {
            return false;
        }

        if (p.isEmpty()) {
            return s.isEmpty();
        }

        boolean first_match = !s.isEmpty() && (s.charAt(0) == p.charAt(0) ||
                p.charAt(0) == '.');

        if (p.length() >= 2 && p.charAt(1) == '*') {
            return (isMatch(s, p.substring(2)) ||
                    (first_match && isMatch(s.substring(1), p)));
        } else {
            return first_match && isMatch(s.substring(1), p.substring(1));
        }
    }

    public static void main(String[] args) {
        RegularExpressionMatching solution = new RegularExpressionMatching();
        System.out.println("" + solution.isMatch("ab", ".*c"));
        System.out.println("false = " + solution.isMatch("aa", "a"));
        System.out.println("true = " + solution.isMatch("aa", "a*"));
        System.out.println("true = " + solution.isMatch("ab", ".*"));
        System.out.println("true = " + solution.isMatch("aab", "c*a*b"));
        System.out.println("false = " + solution.isMatch("mississippi", "mis*is*p*."));
    }
}
