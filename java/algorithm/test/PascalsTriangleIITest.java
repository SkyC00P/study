import org.junit.jupiter.api.Test;
import utils.ListUtils;


import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTriangleIITest {
    PascalsTriangleII solution = new PascalsTriangleII();

    @Test
    void getRow() {
        List list = ListUtils.createList("1,3,3,1").get(0);
        assertIterableEquals(list, solution.getRow(3));
    }
}