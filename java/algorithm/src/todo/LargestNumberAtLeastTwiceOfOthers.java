package todo;

public class LargestNumberAtLeastTwiceOfOthers {

    class Data {
        int index;
        int max_num = 0;
        int last_num = 0;
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Largest Number At Least Twice of Others.
     * Memory Usage: 36.8 MB, less than 49.08% of Java online submissions for Largest Number At Least Twice of Others.
     */
    public int dominantIndex(int[] nums) {
        Data data = new Data();
        data.index = 0;
        data.max_num = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (data.max_num < nums[i]) {
                data.index = i;
                data.last_num = data.max_num;
                data.max_num = nums[i];
            } else if (data.last_num < nums[i]) {
                data.last_num = nums[i];
            }
        }
        return data.max_num >= data.last_num * 2 ? data.index : -1;
    }
}
