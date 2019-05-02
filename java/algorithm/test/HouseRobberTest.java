import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HouseRobberTest {

    HouseRobber solution = new HouseRobber();

    @Test
    void rob() {
        assertEquals(4, solution.rob(new int[]{1, 2, 3, 1}));
        assertEquals(12, solution.rob(new int[]{2, 7, 9, 3, 1}));
        assertEquals(4, solution.rob(new int[]{2, 1, 1, 2}));
    }
}