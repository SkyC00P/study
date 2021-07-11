package done;

import java.util.PriorityQueue;

public class KthLargestElementInAStream {
    /**
     * 最小堆问题
     * Runtime: 16 ms, faster than 72.15% of Java online submissions for Kth Largest Element in a Stream.
     * Memory Usage: 45.1 MB, less than 22.55% of Java online submissions for Kth Largest Element in a Stream.
     */
    static class KthLargest {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        final int k;

        public KthLargest(int k, int[] nums) {
            this.k = k;
            for (int i=0; i<nums.length; i++) {
                add(nums[i]);
            }
        }

        public int add(int val) {
            minHeap.add(val);
            if (minHeap.size() > this.k) {
                minHeap.poll();
            }
            return minHeap.peek();
        }
    }

    public static void main(String[] args) {
        KthLargest kthLargest = new KthLargest(3, new int[]{4, 5, 8, 2});
        System.out.println(kthLargest.add(3));
        System.out.println(kthLargest.add(5));
        System.out.println(kthLargest.add(10));
        System.out.println(kthLargest.add(9));
        System.out.println(kthLargest.add(4));
    }

}
