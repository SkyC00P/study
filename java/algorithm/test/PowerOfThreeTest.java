import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PowerOfThreeTest {

    PowerOfThree solution = new PowerOfThree();

    @Test
    void isPowerOfThree() {
        assertTrue(solution.isPowerOfThree(27));
        assertTrue(!solution.isPowerOfThree(0));
        assertTrue(solution.isPowerOfThree(9));
        assertTrue(!solution.isPowerOfThree(45));
    }
}