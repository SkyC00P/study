package todo;

import java.util.Arrays;

public class DuplicateZeros {
    /**
     * Runtime: 12 ms, faster than 51.20% of Java online submissions for Duplicate Zeros.
     * Memory Usage: 38.8 MB, less than 90.33% of Java online submissions for Duplicate Zeros.
     */
    public void duplicateZeros(int[] arr) {
        int i = 0;
        while (i < arr.length - 1) {
            if (arr[i] == 0) {
                for (int j = i + 1, last = 0; j < arr.length; j++) {
                    int n = arr[j];
                    arr[j] = last;
                    last = n;
                }
                i += 2;
            } else {
                i++;
            }
        }
    }

    public static void main(String[] args) {
        DuplicateZeros main = new DuplicateZeros();
        main.duplicateZeros(new int[]{1, 0, 2, 3, 0, 4, 5, 0});
        main.duplicateZeros(new int[]{1, 2, 3});
    }
}
