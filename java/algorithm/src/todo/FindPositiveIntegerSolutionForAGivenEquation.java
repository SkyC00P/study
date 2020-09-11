package todo;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindPositiveIntegerSolutionForAGivenEquation {

    class CustomFunction {
        // Returns f(x, y) for any given positive integers x and y.
        // Note that f(x, y) is increasing with respect to both x and y.
        // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
        public int f(int x, int y) {
            return 0;
        }
    };

    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> list = new ArrayList<>();
        if (customfunction.f(1, 1) == z) {
            list.add(Arrays.asList(new Integer[] { 1, 1 }));
        } else if (customfunction.f(1000, 1000) == z) {
            list.add(Arrays.asList(new Integer[] { 1000, 1000 }));
        }
        return list;
    }
}
