package done;

import java.util.HashSet;
import java.util.Set;

public class SetMismatch {
    /**
     * Runtime: 12 ms, faster than 29.51% of Java online submissions for Set Mismatch.
     * Memory Usage: 41.3 MB, less than 22.72% of Java online submissions for Set Mismatch.
     */
    public int[] findErrorNums(int[] nums) {
        Set<Integer> repeat = new HashSet<>();
        Set<Integer> noFind = new HashSet<>();
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(num)) {
                repeat.add(num);
            } else {
                set.add(num);
            }
        }

        for (int i = 1; i < nums.length + 1; i++) {
            if (!set.contains(i)) {
                noFind.add(i);
            }
        }
        int[] arr = new int[repeat.size() + noFind.size()];
        int index = 0;
        for (int i : repeat) {
            arr[index] = i;
            index++;
        }
        for (int i : noFind) {
            arr[index] = i;
            index++;
        }
        return arr;
    }
}
