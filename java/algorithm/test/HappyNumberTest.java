import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HappyNumberTest {

    HappyNumber solution = new HappyNumber();

    @Test
    void isHappy() {
        assertTrue(solution.isHappy(19));
    }
}