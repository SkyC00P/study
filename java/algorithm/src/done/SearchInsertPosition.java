package done;

/**
 * 数组已经排序好并且没有重复值
 */
public class SearchInsertPosition {

    /**
     * 这个算法最坏的情况是O（n）,最好的情况是O(1), 平均情况是O(n+1/2)
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Search Insert Position.
     * Memory Usage: 39.8 MB, less than 5.03% of Java online submissions for Search Insert Position
     */
    public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) return 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= target) return i;
        }
        return target > nums[nums.length - 1] ? nums.length : 0;
    }

    /**
     * 二分查找算法三种情况都是O(logN)
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Search Insert Position.
     * Memory Usage: 39.4 MB, less than 20.45% of Java online submissions for Search Insert Position.
     */
    public int searchInsert_1(int[] A, int target) {
        int i = 0, j = A.length - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (A[mid] < target) i = mid + 1;
            else j = mid;
        }
        return (A[i] < target) ? i + 1 : i;
    }

    public static void main(String[] args) {
        SearchInsertPosition solution = new SearchInsertPosition();
        System.out.println(solution.searchInsert(new int[]{1, 3, 5, 6}, 5) == 2);
        System.out.println(solution.searchInsert(new int[]{1, 3, 5, 6}, 2) == 1);
        System.out.println(solution.searchInsert(new int[]{1, 3, 5, 6}, 7) == 4);
        System.out.println(solution.searchInsert(new int[]{1, 3, 5, 6}, 0) == 0);
    }
}
