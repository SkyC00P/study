package done;

public class CountingBits {
    /**
     * Runtime: 1 ms, faster than 99.95% of Java online submissions for Counting Bits.
     * Memory Usage: 43.2 MB, less than 58.73% of Java online submissions for Counting Bits.
     */
    public int[] countBits(int n) {
        int[] arr = new int[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i & (i - 1)] + 1;
        }
        return arr;
    }
}
