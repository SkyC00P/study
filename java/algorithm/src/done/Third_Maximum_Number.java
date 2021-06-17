package done;

import java.util.Arrays;
import java.util.HashSet;

public class Third_Maximum_Number {
    /**
     * Runtime: 5 ms, faster than 26.27% of Java online submissions for Third Maximum Number.
     * Memory Usage: 37.9 MB, less than 96.36% of Java online submissions for Third Maximum Number.
     */
    public int thirdMax(int[] nums) {
        Arrays.sort(nums);
        HashSet<Integer> numSet = new HashSet<>();
        for(int i : nums){
            numSet.add(i);
        }
        if (numSet.size() >= 3) {
            HashSet<Integer> set = new HashSet<>();
            int i = nums.length;
            do {
                set.add(nums[--i]);
            } while (set.size() != 3);
            return nums[i];
        }
        return nums[nums.length - 1];
    }
}
