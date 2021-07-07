package done;

import utils.ArrayUtils;

import java.util.HashMap;
import java.util.Map;

public class Next_Greater_Element_I {

    private Map<Integer, Integer> map = new HashMap<>();

    /**
     * Runtime: 3 ms, faster than 86.97% of Java online submissions for Next Greater Element I.
     * Memory Usage: 40.9 MB, less than 11.80% of Java online submissions for Next Greater Element I.
     */
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        for (int i = 0; i < nums2.length; i++) {
            for (int j = i + 1; j < nums2.length; j++) {
                if (nums2[i] < nums2[j]) {
                    map.put(nums2[i], nums2[j]);
                    break;
                }
            }
        }
        int[] arr = new int[nums1.length];
        for (int i = 0; i < arr.length; i++) {
            Integer gn = map.get(nums1[i]);
            arr[i] = gn == null ? -1 : gn;
        }
        return arr;
    }

    public static void main(String[] args) {
        Next_Greater_Element_I test = new Next_Greater_Element_I();
        int[] arr = test.nextGreaterElement(new int[]{4, 1, 2}, new int[]{1, 3, 4, 2});
        boolean b = ArrayUtils.equals(arr, new int[]{-1, 3, -1});
        System.out.println(b);

        arr = test.nextGreaterElement(new int[]{1, 3, 5, 2, 4}, new int[]{6, 5, 4, 3, 2, 1, 7});
        System.out.println(ArrayUtils.equals(arr, new int[]{7, 7, 7, 7, 7}));
    }
}
