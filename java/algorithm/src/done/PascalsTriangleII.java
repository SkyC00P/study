package done;

import java.util.ArrayList;
import java.util.List;

public class PascalsTriangleII {

    /**
     * Runtime: 1 ms, faster than 84.84% of Java online submissions for Pascal's Triangle II.
     * Memory Usage: 32.5 MB, less than 100.00% of Java online submissions for Pascal's Triangle II.
     */
    public List<Integer> getRow(int rowIndex) {
        return generate(rowIndex + 1).get(rowIndex);
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Pascal's Triangle.
     * Memory Usage: 32.7 MB, less than 100.00% of Java online submissions for Pascal's Triangle
     */
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            list.add(createList(i, list));
        }
        return list;
    }

    private List<Integer> createList(int i, List<List<Integer>> lists) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        if (i == 0) return list;
        if (i > 1) {
            List<Integer> gList = lists.get(i - 1);
            for (int j = 1; j < i; j++) {
                int num = gList.get(j - 1) + gList.get(j);
                list.add(num);
            }
        }
        list.add(1);
        return list;
    }
}
