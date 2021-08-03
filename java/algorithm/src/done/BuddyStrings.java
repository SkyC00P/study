package done;

import java.util.*;

public class BuddyStrings {

    /**
     * Runtime: 3 ms, faster than 50.04% of Java online submissions for Buddy Strings.
     * Memory Usage: 38.8 MB, less than 81.98% of Java online submissions for Buddy Strings.
     */
    public boolean buddyStrings(String s, String goal) {
        if (s.length() != goal.length()) return false;
        Set<Character> set = new HashSet<>();
        List<Character> diff_s = new ArrayList<>();
        List<Character> diff_goal = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = goal.charAt(i);

            if (c1 != c2) {
                diff_s.add(c1);
                diff_goal.add(c2);
                if (diff_s.size() == 2) {
                    for (char ch : diff_s) {
                        if (!diff_goal.contains(ch)) return false;
                    }
                }
                if (diff_s.size() > 3) {
                    return false;
                }

            } else {
                set.add(c1);
            }
        }

        if (diff_s.size() == 1) return false;
        return set.size() < s.length();
    }

    public static void main(String[] args) {
        BuddyStrings main = new BuddyStrings();
        //true
        System.out.println(main.buddyStrings("abcd", "badc"));

    }
}
