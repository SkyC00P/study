import java.util.Arrays;

public class RemoveDuplicatesfromSortedArray {
    public int removeDuplicates(int[] nums) {
        int size = nums.length;
        for (int i = 0; i < size; i++) {

        }
        return size;
    }

    public static void main(String[] args) {
        RemoveDuplicatesfromSortedArray solution = new RemoveDuplicatesfromSortedArray();
        int[] arr_1 = new int[]{1, 1, 2};
        System.out.println(arrToStr(arr_1, solution.removeDuplicates(arr_1)).equals("[1,2]"));

        int[] arr_2 = new int[]{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        System.out.println(arrToStr(arr_2, solution.removeDuplicates(arr_2)).equals("[0,1,2,3,4]"));

    }

    private static String arrToStr(int[] arr_2, int len) {
        if (len == 0) return "[]";
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < len; i++) {
            sb.append(arr_2[i]).append(",");
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

}
