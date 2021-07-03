import done.TwoSumII_InputArrayIsSorted;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TwoSumII_InputArrayIsSortedTest {

    TwoSumII_InputArrayIsSorted solution = new TwoSumII_InputArrayIsSorted();

    @Test
    void twoSum() {
        int[] twoSum = solution.twoSum(new int[]{2, 7, 11, 15}, 9);
        assertNotNull(twoSum);
        assertEquals(1, twoSum[0]);
        assertEquals(2, twoSum[1]);
    }
}
