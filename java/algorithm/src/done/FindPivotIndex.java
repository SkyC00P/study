package done;

public class FindPivotIndex {
    /**
     * Runtime: 2 ms, faster than 33.35% of Java online submissions for Find Pivot Index.
     * Memory Usage: 49.5 MB, less than 7.49% of Java online submissions for Find Pivot Index.
     */
    public int pivotIndex(int[] nums) {
        int n = 0;
        for (int i : nums) {
            n += i;
        }
        for (int i = 0, j = 0; i < nums.length; i++) {
            int num = nums[i];
            n -= num;
            if (n == j) return i;
            j += num;
        }
        return -1;
    }
}
