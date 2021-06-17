package done;

public class ReplaceElementsWithGreatestElementOnRightSide {
    /**
     * Runtime: 1 ms, faster than 99.75% of Java online submissions for Replace
     * Elements with Greatest Element on Right Side. Memory Usage: 40.5 MB, less
     * than 96.20% of Java online submissions for Replace Elements with Greatest
     * Element on Right Side.
     */
    public int[] replaceElements(int[] arr) {
        int max = arr[arr.length - 1];
        arr[arr.length - 1] = -1;
        for (int i = arr.length - 2; i >= 0; i--) {
            int cur = arr[i];
            arr[i] = max;
            if (cur > max) {
                max = cur;
            }
        }
        return arr;
    }
}
