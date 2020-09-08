public class FindN_UniqueIntegersSumUpToZero {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Find N
     * Unique Integers Sum up to Zero. Memory Usage: 37.3 MB, less than 93.26% of
     * Java online submissions for Find N Unique Integers Sum up to Zero.
     */
    public int[] sumZero(int n) {
        int[] arr = new int[n];
        boolean isOdd = (n & 1) == 1;
        for (int i = 0; i < n / 2; i++) {
            int num = i + 1;
            arr[i] = num;
            arr[n - i - 1] = -num;
        }
        if (isOdd)
            arr[n / 2] = 0;

        return arr;
    }
}
