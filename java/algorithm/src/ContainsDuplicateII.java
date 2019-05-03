import java.util.*;

public class ContainsDuplicateII {

    public boolean containsNearbyDuplicate_fail_for_Time_Limit_Exceeded(int[] nums, int k) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + k; j > i; j--) {
                if (j < nums.length && nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Runtime: 7 ms, faster than 92.21% of Java online submissions for Contains Duplicate II.
     * Memory Usage: 43.2 MB, less than 43.02% of Java online submissions for Contains Duplicate II.
     */
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k == 0) return false;
        Set<Integer> set = new HashSet<>();
        int head = 0;
        int tail = head + k < nums.length ? head + k : nums.length - 1;
        int size = tail - head + 1;

        for (int i = head; i <= tail; i++) {
            set.add(nums[i]);
        }

        while (size == set.size()) {
            set.remove(nums[head]);
            head++;
            tail++;
            if (tail >= nums.length) {
                return false;
            }
            set.add(nums[tail]);
        }

        return set.size() < size;
    }
}
