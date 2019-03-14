import java.util.HashSet;

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * <p>
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * <p>
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * <p>
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
public class LengthOfLongestSubstring {

    /**
     * Runtime: 58 ms, faster than 22.41% of Java online submissions for Longest Substring Without Repeating Characters.
     * Memory Usage: 41 MB, less than 6.36% of Java online submissions for Longest Substring Without Repeating Characters.
     */
    public int lengthOfLongestSubstring(String s) {
        char[] chars = s.toCharArray();
        int maxlength = 0;
        HashSet<Character> set = new HashSet<>();
        for (int i = 0; i < chars.length; i++) {
            set.add(chars[i]);
            for (int j = i + 1; j < chars.length; j++) {
                if (set.contains(chars[j])) {
                    break;
                } else {
                    set.add(chars[j]);
                }
            }
            if (set.size() > maxlength) {
                maxlength = set.size();
            }
            set.clear();
        }
        return maxlength;
    }

    public static void main(String[] args) {
        LengthOfLongestSubstring solution = new LengthOfLongestSubstring();
        int length = solution.lengthOfLongestSubstring("abcabcbb");
        System.out.println("abcabcbb = " + length);
        length = solution.lengthOfLongestSubstring("bbbbb");
        System.out.println("bbbbb = " + length);
        length = solution.lengthOfLongestSubstring("pwwkew");
        System.out.println("pwwkew = " + length);
    }
}
