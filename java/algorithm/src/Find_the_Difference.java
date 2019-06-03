import java.util.LinkedList;

public class Find_the_Difference {
    /**
     * Runtime: 5 ms, faster than 23.64% of Java online submissions for Find the Difference.
     * Memory Usage: 35.5 MB, less than 99.46% of Java online submissions for Find the Difference.
     */
    public char findTheDifference(String s, String t) {
        LinkedList<Character> list = new LinkedList<>();
        for (char c : t.toCharArray()) {
            list.add(c);
        }
        for (char c : s.toCharArray()) {
            list.remove(Character.valueOf(c));
        }
        return list.get(0);
    }
}
