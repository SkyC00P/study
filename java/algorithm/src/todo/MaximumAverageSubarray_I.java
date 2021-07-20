package todo;

import java.util.ArrayList;
import java.util.List;

public class MaximumAverageSubarray_I {
    public double findMaxAverage(int[] nums, int k) {
        List<Integer> negative_list = new ArrayList<>();
        List<Integer> positive_list = new ArrayList<>();
        for (int i : nums) {
            if (i >= 0) {
                positive_list.add(i);
            } else {
                negative_list.add(i);
            }
        }
        if (positive_list.size() >= k) {
            positive_list.sort(Integer::compareTo);
            double sum = 0;
            for (int i = positive_list.size() - 1, j = k; j > 0; j--, i--) {
                sum += positive_list.get(i);
            }
            return sum / k;
        }
        return 0;

    }
}
