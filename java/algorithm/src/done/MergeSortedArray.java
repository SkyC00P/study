package done;

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * <p>
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 */
public class MergeSortedArray {


    /**
     * 共享栈？
     * 取数组1的最后一位为缓存，然后对前M+N位进行冒泡比较赋值 ？
     * 插入排序 ？
     * Runtime: 1 ms, faster than 82.38% of Java online submissions for Merge Sorted Array.
     * Memory Usage: 37.3 MB, less than 88.65% of Java online submissions for Merge Sorted Array.
     */
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int len = m;
        int index = 0;
        int start = 0;
        boolean nofind = false;
        for (int i = 0; i < nums2.length; i++) {
            while (index < len && nums1[index] <= nums2[i]) {
                index++;
            }
            if (index == len) {
                start = i;
                nofind = true;
                break;
            } else {
                int k = len < nums1.length ? len : len - 1;
                for (; k > index; k--) {
                    nums1[k] = nums1[k - 1];
                }
                nums1[index] = nums2[i];
                len++;
                index++;
            }
        }

        if (nofind) {
            for (int i = start; i < nums2.length; i++) {
                nums1[len] = nums2[i];
                len++;
            }
        }
    }

    /**
     * 如果该问题转变为两个基本有序的数组，不扩展内存空间，对其进行排序，使得从nums1 -> nums2整体有序
     * 如: nums1 = [1,3,7,9] nums2 = [2,6,8] => nums1 = [1,2,3,6], nums2 = [7,8,9]
     */
    public void sortButNotMerge(int[] nums1, int[] nums2) {

    }

}
