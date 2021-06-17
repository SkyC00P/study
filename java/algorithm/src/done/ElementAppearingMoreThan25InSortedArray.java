package done;

import java.util.HashMap;
import java.util.Map;

public class ElementAppearingMoreThan25InSortedArray {
    /**
     * Runtime: 9 ms, faster than 11.96% of Java online submissions for Element
     * Appearing More Than 25% In Sorted Array. Memory Usage: 40.5 MB, less than
     * 6.94% of Java online submissions for Element Appearing More Than 25% In
     * Sorted Array.
     */
    public int findSpecialInteger(int[] arr) {
        double size = arr.length * 0.20;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        int num = 0;
        for (int i : map.keySet()) {
            int count = map.get(i);
            if (count > size) {
                num = i;
            }
        }
        return num;
    }
}
