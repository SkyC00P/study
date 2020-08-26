import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class RelativeRanks {

    Map<Integer, Integer> RANKS = new HashMap<>();

    /**
     * Runtime: 10 ms, faster than 72.33% of Java online submissions for Relative
     * Ranks. Memory Usage: 40.7 MB, less than 66.00% of Java online submissions for
     * Relative Ranks
     */
    public String[] findRelativeRanks(int[] nums) {
        String[] ranks = new String[nums.length];
        initRanks(nums);
        for (int i = 0; i < nums.length; i++) {
            ranks[i] = getRank(nums[i]);
        }

        return ranks;
    }

    private String getRank(int i) {
        int rank = RANKS.get(i);
        return rank == 1 ? "Gold Medal" : rank == 2 ? "Silver Medal" : rank == 3 ? "Bronze Medal" : rank + "";
    }

    private void initRanks(int[] nums) {
        int[] arr = Arrays.copyOf(nums, nums.length);
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            RANKS.put(arr[i], arr.length - i);
        }
    }

    public static void main(String[] args) {
        RelativeRanks ranks = new RelativeRanks();
        String[] s = ranks.findRelativeRanks(new int[] { 1, 3, 2, 4, 5 });
        System.out.println(Arrays.toString(s));
    }
}