package done;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 914
 */
public class XOfAKindInADeckOfCards {
    /**
     * Runtime: 8 ms, faster than 44.28% of Java online submissions for X of a Kind in a Deck of Cards.
     * Memory Usage: 39.3 MB, less than 49.47% of Java online submissions for X of a Kind in a Deck of Cards.
     */
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck.length < 2) return false;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : deck) {
            map.put(i, 1 + map.getOrDefault(i, 0));
        }

        // Find frequency of each number
        List<Integer> list = new ArrayList<>(map.values());
        int min = list.get(0);
        for (int i : list) min = Math.min(i, min);

        // Find whether they can be divided by the same number
        for (int i = 2; i <= min; i++) {
            if (allDivi(list, i)) return true;
        }
        return false;
    }

    private boolean allDivi(List<Integer> list, int i) {
        for (int a : list) {
            if (a % i != 0) return false;
        }
        return true;
    }
}
