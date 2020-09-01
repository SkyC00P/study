public class ShuffleTheArray {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Shuffle the
     * Array. Memory Usage: 42.9 MB, less than 27.33% of Java online submissions for
     * Shuffle the Array.
     */
    public int[] shuffle(int[] nums, int n) {
        int[] arr = new int[nums.length];
        for (int i = 0, j = 0; i < n; i++, j += 2) {
            int x = nums[i];
            int y = nums[i + n];
            arr[j] = x;
            arr[j + 1] = y;
        }
        return arr;
    }
}