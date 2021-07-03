import done.ReverseString;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseStringTest {

    ReverseString solution = new ReverseString();

    @Test
    void reverseString() {
        char[] chs = new char[]{'h', 'e', 'l', 'l', 'o'};
        char[] chars = new char[]{'o', 'l', 'l', 'e', 'h'};
        solution.reverseString(chs);
        assertArrayEquals(chars, chs);
    }
}
