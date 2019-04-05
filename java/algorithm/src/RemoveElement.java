public class RemoveElement {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Element.
     * Memory Usage: 37.2 MB, less than 96.63% of Java online submissions for Remove Element.
     */
    public int removeElement(int[] nums, int val) {
        int del = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val) del++;
        }
        int size = nums.length - del;
        for (int i = 0; i < size; i++) {
            int j = i;
            while (j < nums.length && nums[j] == val) {
                j++;
            }
            if (i == j) continue;
            if (j < nums.length) {
                nums[i] = nums[j];
                nums[j] = val;
            }
        }
        return size;
    }

    public static void main(String[] args) {
        RemoveElement solution = new RemoveElement();
        int[] arr_1 = new int[]{0, 1, 2, 2, 3, 0, 4, 2};
        System.out.println(arrToString(arr_1, solution.removeElement(arr_1, 2)).equals("[0,1,3,0,4]"));

        int[] arr_2 = new int[]{1};
        System.out.println(arrToString(arr_2, solution.removeElement(arr_2, 1)).equals("[]"));

        int[] arr_3 = new int[]{3, 3};
        System.out.println(arrToString(arr_3, solution.removeElement(arr_3, 3)).equals("[]"));
    }

    private static String arrToString(int[] arr, int len) {
        if (len == 0) return "[]";
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < len; i++) {
            sb.append(arr[i]).append(",");
        }
        sb.deleteCharAt(sb.length() - 1).append("]");
        return sb.toString();
    }
}
