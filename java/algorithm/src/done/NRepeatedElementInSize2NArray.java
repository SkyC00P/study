package done;

import java.util.HashSet;
import java.util.Set;

public class NRepeatedElementInSize2NArray {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for N-Repeated Element in Size 2N Array.
     * Memory Usage: 40 MB, less than 48.22% of Java online submissions for N-Repeated Element in Size 2N Array.
     */
    public int repeatedNTimes(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) {
            int size = set.size();
            set.add(n);
            if (size == set.size()) return n;
        }
        return -1;
    }
}
