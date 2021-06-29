package done;

import java.util.ArrayList;
import java.util.List;

public class SummaryRanges {
    /**
     * Runtime: 9 ms, faster than 13.36% of Java online submissions for Summary Ranges.
     * Memory Usage: 38.1 MB, less than 16.51% of Java online submissions for Summary Ranges.
     */
    public List<String> summaryRanges(int[] nums) {
        List<String> list = new ArrayList<>();

        if (nums.length == 0) return list;

        if (nums.length == 1) {
            list.add(nums[0] + "");
            return list;
        }
        int l = 0, r = 1;
        while (l != nums.length) {
            int count = 0;
            while (r != nums.length && nums[r] - nums[r - 1] == 1) {
                r += 1;
                count += 1;
            }

            String range = count == 0 ? nums[l] + "" :
                    String.format("%d->%d", nums[l], nums[r - 1]);
            list.add(range);
            l = r;
            r = l + 1;
        }
        return list;
    }

    public static void main(String[] args) {
        SummaryRanges main = new SummaryRanges();
        System.out.println(main.summaryRanges(new int[]{0, 1, 2, 4, 5, 7}));
        System.out.println(main.summaryRanges(new int[]{0, 2, 3, 4, 6, 8, 9}));
    }
}
