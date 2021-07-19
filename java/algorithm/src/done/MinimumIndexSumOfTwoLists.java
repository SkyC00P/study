package done;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MinimumIndexSumOfTwoLists {
    class Data {
        String name;
        Integer index_1;
        Integer index_2;

        public Integer sum() {
            if (index_1 == null || index_2 == null) return null;
            return index_1 + index_2;
        }
    }

    /**
     * Runtime: 14 ms, faster than 31.64% of Java online submissions for Minimum Index Sum of Two Lists.
     * Memory Usage: 39.9 MB, less than 39.77% of Java online submissions for Minimum Index Sum of Two Lists.
     */
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Data> map = new HashMap<>();
        for (int i = 0; i < list1.length; i++) {
            Data d = map.getOrDefault(list1[i], new Data());
            d.name = list1[i];
            d.index_1 = i;
            map.put(list1[i], d);
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < list2.length; i++) {
            Data d = map.getOrDefault(list2[i], new Data());
            d.index_2 = i;
            map.put(list2[i], d);
        }

        Map<Integer, List<Data>> sum_map = new HashMap<>();
        for (String k : map.keySet()) {
            Data d = map.get(k);
            Integer sum = d.sum();
            if (sum == null) continue;
            if (sum < min) {
                min = sum;
            }
            List<Data> list = sum_map.getOrDefault(sum, new ArrayList<>());
            list.add(d);
            sum_map.put(sum, list);
        }
        List<Data> list = sum_map.get(min);
        String[] arr = new String[list.size()];
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i).name;
        }
        return arr;
    }
}
