import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

class ContainsDuplicateTest {

    ContainsDuplicate solution = new ContainsDuplicate();

    @Test
    void containsDuplicate() {
        assertTrue(solution.containsDuplicate(new int[]{1, 2, 3, 1}));
        assertFalse(solution.containsDuplicate(new int[]{1, 2, 3, 4}));
        assertTrue(solution.containsDuplicate(new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}));
    }

}