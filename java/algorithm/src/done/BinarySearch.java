package done;

public class BinarySearch {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary
     * Search. Memory Usage: 39.9 MB, less than 99.79% of Java online submissions
     * for Binary Search.
     */
    public int search(int[] nums, int target) {
        return search(nums, target, 0, nums.length - 1);
    }

    private int search(int[] nums, int target, int left, int right) {
        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }
        if (right - left <= 1) {
            return -1;
        }
        int mid = (left + right) / 2;
        int n = nums[mid];
        return n < target ? search(nums, target, mid, right) : search(nums, target, left, mid);
    }
}
