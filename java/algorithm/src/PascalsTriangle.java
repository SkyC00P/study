import java.util.ArrayList;
import java.util.List;

/**
 * Input: 5
 * Output:
 * [
 * [1],
 * [1,1],
 * [1,2,1],
 * [1,3,3,1],
 * [1,4,6,4,1]
 * ]
 */
public class PascalsTriangle {
    public List<List<Integer>> generate(int numRows) {
        if (numRows == 0) return null;
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            list.add(createList(i,list));
        }
        return list;
    }

    private List<Integer> createList(int i, List<List<Integer>> lists) {
        List<Integer> list = new ArrayList<>();
        if(i == 0){
            list.add(1);
        }else{
            
        }

        return list;
    }
}
