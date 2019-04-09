public class PlusOne {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Plus One.
     * Memory Usage: 37.4 MB, less than 17.02% of Java online submissions for Plus One.
     */
    public int[] plusOne(int[] digits) {
        digits[digits.length - 1] = digits[digits.length - 1] + 1;
        int index = digits.length - 1;
        while (digits[index] == 10) {
            if (index >= 1) {
                digits[index] = 0;
                index--;
                digits[index] = digits[index] + 1;
            } else {
                break;
            }
        }
        if (digits[0] == 10) {
            int[] arr = new int[digits.length + 1];
            arr[0] = 1;
            System.arraycopy(arr, 1, digits, 0, digits.length);
            return arr;
        }
        return digits;
    }

}
