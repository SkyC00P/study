import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Third_Maximum_NumberTest {

    Third_Maximum_Number test = new Third_Maximum_Number();

    @Test
    void thirdMax() {
        assertEquals(1, test.thirdMax(new int[]{3, 2, 1}));
        assertEquals(2, test.thirdMax(new int[]{1, 2}));
        assertEquals(1, test.thirdMax(new int[]{2, 2, 3, 1}));
        assertEquals(2, test.thirdMax(new int[]{1, 1, 2}));
    }
}