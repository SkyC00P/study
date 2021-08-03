package done;

public class PeakIndexInAMountainArray {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Peak Index in a Mountain Array.
     * Memory Usage: 39.4 MB, less than 39.99% of Java online submissions for Peak Index in a Mountain Array.
     */
    public int peakIndexInMountainArray(int[] arr) {
        for (int i = 0; i + 2 < arr.length; i++) {
            int n1 = arr[i];
            int n2 = arr[i + 1];
            int n3 = arr[i + 2];
            if (n1 < n2 && n2 > n3) return i + 1;
        }
        return -1;
    }

}
