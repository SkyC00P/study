import java.util.HashSet;
import java.util.Set;

public class Intersection_of_Two_Arrays {
    /**
     * Runtime: 2 ms, faster than 97.53% of Java online submissions for Intersection of Two Arrays.
     * Memory Usage: 35.9 MB, less than 68.20% of Java online submissions for Intersection of Two Arrays.
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        for (int i : nums1) {
            set.add(i);
        }

        Set<Integer> arrSet = new HashSet<>();
        for (int i : nums2) {
            if (set.remove(i))
                arrSet.add(i);
        }
        int[] b = new int[arrSet.size()];
        int k = 0;
        for (int i : arrSet) {
            b[k++] = i;
        }
        return b;
    }
}
