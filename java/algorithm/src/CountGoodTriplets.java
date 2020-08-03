public class CountGoodTriplets {
    /**
     * Runtime: 20 ms, faster than 60.00% of Java online submissions for Count Good
     * Triplets. Memory Usage: 37.4 MB, less than 100.00% of Java online submissions
     * for Count Good Triplets.
     */
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int count = 0;
        for (int i = 0; i + 2 < arr.length; i++) {
            for (int j = i + 1; j + 1 < arr.length; j++) {
                for (int k = j + 1; k < arr.length; k++) {
                    int ai = arr[i];
                    int aj = arr[j];
                    int ak = arr[k];

                    int diff_i = Math.abs(ai - aj);
                    int diff_j = Math.abs(aj - ak);
                    int diff_k = Math.abs(ai - ak);

                    if (diff_i <= a && diff_j <= b && diff_k <= c) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}