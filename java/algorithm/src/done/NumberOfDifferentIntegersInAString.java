package done;

import java.util.HashSet;
import java.util.Set;

public class NumberOfDifferentIntegersInAString {
    /**
     * Runtime: 11 ms, faster than 31.95% of Java online submissions for Number of Different Integers in a String.
     * Memory Usage: 38.9 MB, less than 52.95% of Java online submissions for Number of Different Integers in a String.
     */
    public int numDifferentIntegers(String word) {
        char[] chs = word.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            if (chs[i] >= 'a' && chs[i] <= 'z') {
                chs[i] = ' ';
            }
        }
        String ns = new String(chs);

        Set<String> hash = new HashSet<>();
        String[] arr = ns.split("\\s+");
        for (String s : arr) {
            s = s.trim().replaceFirst("^0+(?!$)", "");
            if (!s.isEmpty() && Character.isDigit(s.charAt(0))) {
                hash.add(s);
            }
        }
        return hash.size();
    }

    public static void main(String[] args) {
        NumberOfDifferentIntegersInAString main = new NumberOfDifferentIntegersInAString();
        int i = main.numDifferentIntegers("167278959591294");
        System.out.println(i);
    }
}
