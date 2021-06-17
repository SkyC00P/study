package done;

import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicate {
    /**
     * Runtime: 9 ms, faster than 57.31% of Java online submissions for Contains Duplicate.
     * Memory Usage: 45.1 MB, less than 5.03% of Java online submissions for Contains Duplicate
     */
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if(set.remove(nums[i])){
                return true;
            }
            set.add(nums[i]);
        }

        return false;
    }
}
