package done;

import java.util.ArrayList;
import java.util.List;

public class PositionsOfLargeGroups {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Positions of Large Groups.
     * Memory Usage: 39.3 MB, less than 52.42% of Java online submissions for Positions of Large Groups.
     */
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < s.length(); ) {
            char ch = s.charAt(i);
            int count = 0;
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(j) == ch) count++;
                else break;
            }
            List<Integer> pair = new ArrayList<>();
            pair.add(i);
            pair.add(i + count);
            if (count >= 2) {
                list.add(pair);
            }
            i = count + i + 1;
        }
        return list;
    }

    public static void main(String[] args) {
        PositionsOfLargeGroups main = new PositionsOfLargeGroups();
//        System.out.println(main.largeGroupPositions("abbxxxxzzy"));
        // "abcdddeeeeaabbbcd"
        System.out.println(main.largeGroupPositions("abcdddeeeeaabbbcd"));
    }
}
