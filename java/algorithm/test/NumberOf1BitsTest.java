import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NumberOf1BitsTest {

    NumberOf1Bits solution = new NumberOf1Bits();

    @Test
    void hammingWeight() {
        assertEquals(3, solution.hammingWeight(11));
        assertEquals(1, solution.hammingWeight(128));
        assertEquals(31, solution.hammingWeight(-3));
    }

    @Test
    void hammingWeight_1() {
        assertEquals(3, solution.hammingWeight_1(11));
        assertEquals(1, solution.hammingWeight_1(128));
        assertEquals(31, solution.hammingWeight_1(-3));
    }

}