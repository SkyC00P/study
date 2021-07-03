import done.RansomNote;
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

    @Test
    void canConstruct1() {
        assertFalse(solution.canConstruct1("a", "b"));
        assertFalse(solution.canConstruct1("aa", "ab"));
        assertTrue(solution.canConstruct1("aa", "aab"));
        assertTrue(solution.canConstruct1("", ""));
        assertFalse(solution.canConstruct1("a", ""));
    }
}
