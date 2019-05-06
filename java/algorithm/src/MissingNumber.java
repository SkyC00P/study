import java.util.HashSet;
import java.util.Set;

public class MissingNumber {
    /**
     * Runtime: 10 ms, faster than 6.53% of Java online submissions for Missing Number.
     * Memory Usage: 40.9 MB, less than 61.27% of Java online submissions for Missing Number.
     */
    public int missingNumber(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        Set<Integer> set = new HashSet<>();
        for (int i : nums) set.add(i);
        for (int i = 0; i < nums.length; i++) {
            if (!set.remove(i)) return i;
        }
        return nums.length;
    }
}