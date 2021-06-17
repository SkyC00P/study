package done;

public class RemoveDuplicatesfromSortedArray {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted Array.
     * Memory Usage: 40.9 MB, less than 84.12% of Java online submissions for Remove Duplicates from Sorted Array.
     */
    public int removeDuplicates(int[] nums) {
        int size = nums.length;
        int j = 1;
        for (int i = 0; i < nums.length; i++) {
            int k = j;
            while (k < nums.length && nums[k] == nums[i]) {
                size--;
                k++;
            }
            if (k < nums.length && nums[k] != nums[i]) {
                nums[i + 1] = nums[k];
            }
            j = k + 1;
        }
        return size;
    }

    public static void main(String[] args) {
        RemoveDuplicatesfromSortedArray solution = new RemoveDuplicatesfromSortedArray();
        int[] arr_1 = new int[]{1, 1, 2};
        System.out.println(arrToStr(arr_1, solution.removeDuplicates(arr_1)).equals("[1,2]"));

        int[] arr_2 = new int[]{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        System.out.println(arrToStr(arr_2, solution.removeDuplicates(arr_2)).equals("[0,1,2,3,4]"));

        int[] arr_3 = new int[]{1, 2, 2};
        System.out.println(arrToStr(arr_3, solution.removeDuplicates(arr_3)).equals("[1,2]"));

        int[] arr_4 = new int[]{1, 2};
        System.out.println(arrToStr(arr_4, solution.removeDuplicates(arr_4)).equals("[1,2]"));

        int[] arr_5 = new int[]{1, 1};
        System.out.println(arrToStr(arr_5, solution.removeDuplicates(arr_5)).equals("[1]"));
    }

    private static String arrToStr(int[] arr_2, int len) {
        if (len == 0) return "[]";
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < len; i++) {
            sb.append(arr_2[i]).append(",");
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append("]");
        System.out.println("arrToStr->" + sb.toString());
        return sb.toString();
    }

}
