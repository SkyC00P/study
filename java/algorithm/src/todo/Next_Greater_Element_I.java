package todo;

import utils.ArrayUtils;

public class Next_Greater_Element_I {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        return null;
    }

    public static void main(String[] args) {
        Next_Greater_Element_I test = new Next_Greater_Element_I();
        int[] arr = test.nextGreaterElement(new int[]{4, 1, 2}, new int[]{1, 3, 4, 2});
        boolean b = ArrayUtils.equals(arr, new int[]{-1, 3, -1});
        System.out.println(b);
    }
}
