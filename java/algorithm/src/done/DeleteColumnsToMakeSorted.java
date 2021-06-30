package done;

import java.util.*;

public class DeleteColumnsToMakeSorted {

    class Data {
        private Map<Integer, List<Character>> cols = new HashMap<>();
        private Set<Integer> rm = new HashSet<>();

        public void put(int j, char ch) {
            if (rm.contains(j)) {
                return;
            }
            List<Character> list = cols.getOrDefault(j, new ArrayList<>());
            if (list.isEmpty()) list.add(ch);

            char last_ch = list.get(list.size() - 1);
            if (ch - last_ch < 0) {
                rm.add(j);
                return;
            } else {
                list.add(ch);
            }
            cols.put(j, list);
        }
    }

    /**
     * Runtime: 76 ms, faster than 5.03% of Java online submissions for Delete Columns to Make Sorted.
     * Memory Usage: 46.7 MB, less than 6.40% of Java online submissions for Delete Columns to Make Sorted.
     */
    public int minDeletionSize(String[] strs) {
        Data data = new Data();
        for (int i = 0; i < strs.length; i++) {
            String s = strs[i];
            for (int j = 0; j < s.length(); j++) {
                data.put(j, s.charAt(j));
            }
        }
        return data.rm.size();
    }
}
