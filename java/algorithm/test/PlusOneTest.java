import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PlusOneTest {

    PlusOne solution = new PlusOne();

    @Test
    void plusOne() {
        assertArrayEquals(new int[]{1}, solution.plusOne(new int[]{0}));
        assertArrayEquals(new int[]{1, 2, 4}, solution.plusOne(new int[]{1, 2, 3}));
        assertArrayEquals(new int[]{4, 3, 2, 2}, solution.plusOne(new int[]{4, 3, 2, 1}));
        assertArrayEquals(new int[]{1, 0}, solution.plusOne(new int[]{9}));
        assertArrayEquals(new int[]{1, 0, 0}, solution.plusOne(new int[]{9, 9}));
    }
}