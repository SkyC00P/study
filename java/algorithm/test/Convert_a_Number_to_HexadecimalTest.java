import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Convert_a_Number_to_HexadecimalTest {

    Convert_a_Number_to_Hexadecimal solution = new Convert_a_Number_to_Hexadecimal();

    @Test
    void toHex() {
        assertEquals("1a", solution.toHex(26));
        assertEquals("ffffffff", solution.toHex(-1));
        assertEquals("10", solution.toHex(16));
    }
}