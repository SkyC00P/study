import org.junit.jupiter.api.Test;
import utils.ListUtils;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTriangleTest {

    PascalsTriangle solution = new PascalsTriangle();

    @Test
    void generate() {
        List<List<Integer>> list = ListUtils.createList("1|1,1|1,2,1|1,3,3,1|1,4,6,4,1");
        ListUtils.print(list);
        assertIterableEquals(list, solution.generate(5));
    }
}