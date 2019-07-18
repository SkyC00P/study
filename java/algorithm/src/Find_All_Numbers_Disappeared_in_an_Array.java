import java.util.ArrayList;
import java.util.List;

public class Find_All_Numbers_Disappeared_in_an_Array {
    /**
     * Time Limit Exceeded
     */
    public static List<Integer> findDisappearedNumbers_fail(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int read = 1; read <= nums.length; read++) {
            list.add(read);
        }
        for (int i = 0; i < nums.length; i++) {
            list.remove(Integer.valueOf(nums[i]));
        }
        return list;
    }

    /**
     * Runtime: 6 ms, faster than 80.14% of Java online submissions for Find All Numbers Disappeared in an Array.
     * Memory Usage: 47.4 MB, less than 95.86% of Java online submissions for Find All Numbers Disappeared in an Array
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int disappear = nums.length + 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == i + 1) continue;
            int j = nums[i];
            while (j != disappear && nums[j - 1] != j) {
                int k = nums[j - 1];
                nums[j - 1] = j;
                j = k;
            }
            if (nums[i] != i + 1) {
                nums[i] = disappear;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == disappear) {
                list.add(i + 1);
            }
        }
        return list;
    }

}
