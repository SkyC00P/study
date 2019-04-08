import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LengthOfLastWordTest {

    LengthOfLastWord solution = new LengthOfLastWord();

    @Test
    void lengthOfLastWord() {
        assertEquals(5, solution.lengthOfLastWord("Hello World"));
        assertEquals(4, solution.lengthOfLastWord("a aaaa "));
        assertEquals(5, solution.lengthOfLastWord("12345 "));
    }
}