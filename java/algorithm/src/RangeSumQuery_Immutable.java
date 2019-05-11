public class RangeSumQuery_Immutable {
    /**
     * Runtime: 235 ms, faster than 20.34% of Java online submissions for Range Sum Query - Immutable.
     * Memory Usage: 60 MB, less than 19.70% of Java online submissions for Range Sum Query - Immutable.
     */
    public static class NumArray {
        private int[] nums;

        public NumArray(int[] nums) {
            this.nums = nums;
        }

        public int sumRange(int i, int j) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            return sum;
        }
    }
}
