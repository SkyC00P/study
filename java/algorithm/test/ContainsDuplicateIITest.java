import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ContainsDuplicateIITest {

    ContainsDuplicateII solution = new ContainsDuplicateII();

    @Test
    void containsNearbyDuplicate() {

        assertTrue(solution.containsNearbyDuplicate(new int[]{1, 2, 3, 1}, 3));
        assertTrue(solution.containsNearbyDuplicate(new int[]{1, 0, 1, 1}, 1));
        assertFalse(solution.containsNearbyDuplicate(new int[]{1, 2, 3, 1, 2, 3}, 2));
        assertTrue(solution.containsNearbyDuplicate(new int[]{99, 99}, 2));
    }

}