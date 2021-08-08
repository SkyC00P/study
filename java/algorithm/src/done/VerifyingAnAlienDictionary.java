package done;

import java.util.HashMap;
import java.util.Map;

public class VerifyingAnAlienDictionary {
    /**
     * Runtime: 1 ms, faster than 51.29% of Java online submissions for Verifying an Alien Dictionary.
     * Memory Usage: 38.9 MB, less than 58.53% of Java online submissions for Verifying an Alien Dictionary.
     */
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> dict = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            dict.put(order.charAt(i), i);
        }

        for (int i = 0; i < words.length - 1; i++) {
            String s1 = words[i];
            String s2 = words[i + 1];

            if (notDictOrder(dict, s1, s2)) return false;
        }
        return true;
    }

    private boolean notDictOrder(Map<Character, Integer> dict, String s1, String s2) {
        char[] value = s1.toCharArray();
        char[] other = s2.toCharArray();
        int len1 = s1.length();
        int len2 = s2.length();
        int lim = Math.min(len1, len2);
        for (int k = 0; k < lim; k++) {
            if (value[k] != other[k]) {
                return dict.get(value[k]) > dict.get(other[k]);
            }
        }
        return len1 > len2;
    }

    public static void main(String[] args) {
        VerifyingAnAlienDictionary main = new VerifyingAnAlienDictionary();
        System.out.println(main.isAlienSorted(new String[]{"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz"));
        // ["kuvp","q"]
        //"ngxlkthsjuoqcpavbfdermiywz"
        System.out.println(main.isAlienSorted(new String[]{"kuvp", "q"}, "ngxlkthsjuoqcpavbfdermiywz"));
    }
}
