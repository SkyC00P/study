import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CountPrimesTest {

    CountPrimes solution = new CountPrimes();

    @Test
    void countPrimes() {
        assertEquals(4, solution.countPrimes(10));
        assertEquals(3, solution.countPrimes(7));
        assertEquals(0, solution.countPrimes(2));
    }
}