import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SingleNumberTest {
    SingleNumber solution = new SingleNumber();

    @Test
    void singleNumber() {
        assertEquals(1, solution.singleNumber(new int[]{2, 2, 1}));
        assertEquals(4, solution.singleNumber(new int[]{4, 1, 2, 1, 2}));
    }
}