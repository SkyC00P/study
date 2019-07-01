import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RangeSumQuery_ImmutableTest {

    int[] arr = new int[]{-2, 0, 3, -5, 2, -1};

    @Test
    public void test() {
        RangeSumQuery_Immutable.NumArray array = new RangeSumQuery_Immutable.NumArray(arr);
        assertEquals(1, array.sumRange(0, 2));
        assertEquals(-1, array.sumRange(2, 5));
        assertEquals(-3, array.sumRange(0, 5));
    }

    @Test
    public void t1() {
        RangeSumQuery_Immutable.NumArray1 array = new RangeSumQuery_Immutable.NumArray1(arr);
        assertEquals(1, array.sumRange(0, 2));
        assertEquals(-1, array.sumRange(2, 5));
        assertEquals(-3, array.sumRange(0, 5));
    }
}