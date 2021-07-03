import done.AddDigits;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddDigitsTest {

    AddDigits solution = new AddDigits();

    @Test
    void addDigits() {
        assertEquals(2, solution.addDigits(38));
    }

    @Test
    void addDigits1(){
        assertEquals(2, solution.addDigits1(38));
    }
}
