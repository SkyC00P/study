import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FirstBadVersionTest {

    FirstBadVersion solution = new FirstBadVersion();

    @Test
    void firstBadVersion() {
        solution.setBadVersion(4);
        assertEquals(4, solution.firstBadVersion(5));
        solution.setBadVersion(1);
        assertEquals(1, solution.firstBadVersion(6));
        assertEquals(1, solution.firstBadVersion(1));
        solution.setBadVersion(1702766719);
        assertEquals(1702766719, solution.firstBadVersion(2126753390));

        solution.setBadVersion(2);
        assertEquals(2, solution.firstBadVersion(4));
    }
}