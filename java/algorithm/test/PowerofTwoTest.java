import done.PowerofTwo;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PowerofTwoTest {

    PowerofTwo solution = new PowerofTwo();

    @Test
    void isPowerOfTwo() {
        System.out.println(Integer.MAX_VALUE);
        assertTrue(solution.isPowerOfTwo(1));
        assertTrue(solution.isPowerOfTwo(16));
        assertTrue(!solution.isPowerOfTwo(218));
        assertTrue(!solution.isPowerOfTwo(1073741825));
        assertFalse(solution.isPowerOfTwo(2147483647));
    }
}
