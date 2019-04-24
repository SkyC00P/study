import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SingleNumberTest {
    SingleNumber solution = new SingleNumber();

    @Test
    void singleNumber() {
        assertEquals(1, solution.singleNumber(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber(new int[]{4, 1, 2, 1, 2}));
        assertEquals(2, solution.singleNumber(new int[]{1, 2, 1}));
        assertEquals(0, solution.singleNumber(new int[]{1, 1}));
    }


    @Test
    void singleNumber_1() {
        assertEquals(1, solution.singleNumber_1(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber_1(new int[]{4, 1, 2, 1, 2}));
        assertEquals(2, solution.singleNumber_1(new int[]{1, 2, 1}));
        assertEquals(0, solution.singleNumber_1(new int[]{1, 1}));
    }

    @Test
    void singleNumber_2() {
        assertEquals(1, solution.singleNumber_2(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber_2(new int[]{4, 1, 2, 1, 2}));
        assertEquals(2, solution.singleNumber_2(new int[]{1, 2, 1}));
        assertEquals(0, solution.singleNumber_2(new int[]{1, 1}));
    }

    @Test
    void singleNumber_3() {
        assertEquals(1, solution.singleNumber_3(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber_3(new int[]{4, 1, 2, 1, 2}));
        assertEquals(2, solution.singleNumber_3(new int[]{1, 2, 1}));
        assertEquals(0, solution.singleNumber_3(new int[]{1, 1}));
    }

    @Test
    void singleNumber_4() {
        assertEquals(1, solution.singleNumber_4(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber_4(new int[]{4, 1, 2, 1, 2}));
        assertEquals(2, solution.singleNumber_4(new int[]{1, 2, 1}));
        assertEquals(0, solution.singleNumber_4(new int[]{1, 1}));
    }

    @Test
    void singleNumber_5() {
        assertEquals(1, solution.singleNumber_5(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber_5(new int[]{4, 1, 2, 1, 2}));
        assertEquals(2, solution.singleNumber_5(new int[]{1, 2, 1}));
        assertEquals(0, solution.singleNumber_5(new int[]{1, 1}));
    }
}