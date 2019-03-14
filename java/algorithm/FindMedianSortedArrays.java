import java.util.Arrays;
import java.util.Collections;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * <p>
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * <p>
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 */
public class FindMedianSortedArrays {

    /**
     * Runtime: 26 ms, faster than 68.62% of Java online submissions for Median of Two Sorted Arrays.
     * Memory Usage: 49.4 MB, less than 49.45% of Java online submissions for Median of Two Sorted Arrays.
     */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] n = new int[nums1.length + nums2.length];

        System.arraycopy(nums1, 0, n, 0, nums1.length);
        System.arraycopy(nums2, 0, n, nums1.length, nums2.length);
        Arrays.sort(n);
        double d = 0.0;
        if ((n.length & 1) == 0) {
            int l_index = n.length / 2 - 1;
            int r_index = n.length / 2;
            d = (double) (n[l_index] + n[r_index]) / 2;
        } else {
            int index = (n.length - 1) / 2;
            d = n[index];
        }
        return d;
    }

    public static void main(String[] args) {
        FindMedianSortedArrays solution = new FindMedianSortedArrays();

        double d ;
        d = solution.findMedianSortedArrays(new int[]{1,2},new int[]{3,4});
        System.out.println(d);
        d = solution.findMedianSortedArrays(new int[]{1,3},new int[]{2});
        System.out.println(d);
    }
}
