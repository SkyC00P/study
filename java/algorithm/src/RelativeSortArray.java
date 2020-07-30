import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RelativeSortArray {
    /**
     * Runtime: 6 ms, faster than 21.73% of Java online submissions for Relative
     * Sort Array. Memory Usage: 39.4 MB, less than 40.88% of Java online
     * submissions for Relative Sort Array.
     */
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr1) {
            int count = map.getOrDefault(i, 0);
            map.put(i, count + 1);
        }
        List<Integer> list = new ArrayList<>();
        for (int i : arr2) {
            int len = map.remove(i);
            for (int j = 0; j < len; j++) {
                list.add(i);
            }
        }
        if (!map.isEmpty()) {
            List<Integer> _list = new ArrayList<>();
            for (int i : map.keySet()) {
                int len = map.get(i);
                for (int j = 0; j < len; j++) {
                    _list.add(i);
                }
            }
            _list.sort((a, b) -> {
                return a - b;
            });
            list.addAll(_list);
        }
        return list.stream().mapToInt(Integer::valueOf).toArray();
    }

    public static void main(String[] args) {
        RelativeSortArray rArray = new RelativeSortArray();
        int[] arr = rArray.relativeSortArray(new int[] { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 },
                new int[] { 2, 1, 4, 3, 9, 6 });
        System.out.println(Arrays.toString(arr));

        int[] arr1 = rArray.relativeSortArray(
                new int[] { 2, 21, 43, 38, 0, 42, 33, 7, 24, 13, 12, 27, 12, 24, 5, 23, 29, 48, 30, 31 },
                new int[] { 2, 42, 38, 0, 43, 21 });
        System.out.println(Arrays.toString(arr1));
    }
}