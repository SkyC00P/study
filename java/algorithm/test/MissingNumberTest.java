import done.MissingNumber;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MissingNumberTest {

    MissingNumber solution = new MissingNumber();

    @Test
    void missingNumber() {
        assertEquals(2, solution.missingNumber(new int[]{3, 0, 1}));
        assertEquals(8, solution.missingNumber(new int[]{9, 6, 4, 2, 3, 5, 7, 0, 1}));
        assertEquals(1, solution.missingNumber(new int[]{0}));
    }
}
