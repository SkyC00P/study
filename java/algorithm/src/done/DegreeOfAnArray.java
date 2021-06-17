package done;

import java.util.HashMap;
import java.util.Map;

public class DegreeOfAnArray {

    class Data {
        int count;
        int min = -1;
        int max = 0;

        public void putIndex(int i) {
            if (min == -1) min = i;
            max = i;
        }
    }

    /**
     * Runtime: 10 ms, faster than 88.96% of Java online submissions for Degree of an Array.
     * Memory Usage: 44.6 MB, less than 21.52% of Java online submissions for Degree of an Array.
     */
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Data> map = new HashMap<>();
        int max_num = -1, count = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            Data d = map.getOrDefault(num, new Data());
            d.count = d.count + 1;
            d.putIndex(i);

            if (d.count > count) {
                max_num = num;
                count = d.count;
            }
            map.put(num, d);
        }

        int min = Integer.MAX_VALUE;
        for (Data d : map.values()) {
            if (d.count != count) continue;
            min = Math.min(min, d.max - d.min + 1);
        }
        return min;
    }

    public static void main(String[] args) {
        DegreeOfAnArray main = new DegreeOfAnArray();
        System.out.println(main.findShortestSubArray(new int[]{1, 1}) == 2);
        System.out.println(main.findShortestSubArray(new int[]{1, 2, 2, 3, 1}) == 2);
        System.out.println(main.findShortestSubArray(new int[]{2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2}) == 7);
    }
}
