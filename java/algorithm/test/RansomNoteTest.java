import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RansomNoteTest {

    RansomNote solution = new RansomNote();

    @Test
    void canConstruct() {
        assertFalse(solution.canConstruct("a", "b"));
        assertFalse(solution.canConstruct("aa", "ab"));
        assertTrue(solution.canConstruct("aa", "aab"));
        assertFalse(solution.canConstruct("a", ""));
    }
}