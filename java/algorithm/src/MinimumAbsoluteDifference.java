import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MinimumAbsoluteDifference {
    /**
     * Time Limit Exceeded
     */
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Map<Integer, List<List<Integer>>> map = new HashMap<>();
        int len = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                len = arr[i] - arr[j];
                if (len > 0) {
                    List<List<Integer>> list = map.getOrDefault(len, new ArrayList<>());
                    List<Integer> pairs = new ArrayList<>();
                    pairs.add(arr[j]);
                    pairs.add(arr[i]);
                    list.add(pairs);
                    map.put(len, list);
                } else {
                    List<List<Integer>> list = map.getOrDefault(-len, new ArrayList<>());
                    List<Integer> pairs = new ArrayList<>();
                    pairs.add(arr[i]);
                    pairs.add(arr[j]);
                    list.add(pairs);
                    map.put(-len, list);
                }
            }
        }
        int min = len > 0 ? len : -len;
        for (int i : map.keySet()) {
            if (i < min) {
                min = i;
            }
        }
        List<List<Integer>> list = map.get(min);
        list.sort((a, b) -> {
            return a.get(0) - b.get(0);
        });
        return list;
    }
}