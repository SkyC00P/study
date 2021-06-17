package done;

import java.util.Arrays;

public class MakeTwoArraysEqualByReversingSubArrays {
    /**
     * Runtime: 6 ms, faster than 29.40% of Java online submissions for Make Two
     * Arrays Equal by Reversing Sub-arrays. Memory Usage: 43.4 MB, less than 19.37%
     * of Java online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
     */
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        return Arrays.equals(target, arr);
    }
}
