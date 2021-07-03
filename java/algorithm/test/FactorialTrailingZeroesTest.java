import done.FactorialTrailingZeroes;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FactorialTrailingZeroesTest {

    FactorialTrailingZeroes solution = new FactorialTrailingZeroes();

    @Test
    void trailingZeroes() {
        assertEquals(0, solution.trailingZeroes(0));
        assertEquals(0, solution.trailingZeroes(3));
        assertEquals(1, solution.trailingZeroes(5));
        assertEquals(2, solution.trailingZeroes(10));
        assertEquals(2, solution.trailingZeroes(12));
        assertEquals(452137076, solution.trailingZeroes(1808548329));
    }
}
