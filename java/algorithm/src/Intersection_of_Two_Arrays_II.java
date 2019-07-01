import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */
public class Intersection_of_Two_Arrays_II {

    /**
     * Runtime: 4 ms, faster than 24.93% of Java online submissions for Intersection of Two Arrays II.
     * Memory Usage: 35.8 MB, less than 64.84% of Java online submissions for Intersection of Two Arrays II
     */
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> n1_list = new ArrayList<>();
        for (int i : nums1) {
            n1_list.add(i);
        }

        List<Integer> list = new ArrayList<>();
        for (int i : nums2) {
            if(n1_list.remove(Integer.valueOf(i))){
                list.add(i);
            }
        }
        int[] b = new int[list.size()];
        int k = 0;
        for (int i : list) {
            b[k++] = i;
        }
        return b;
    }
}
