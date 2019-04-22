import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimetoBuyandSellStockIITest {

    BestTimetoBuyandSellStockII solution = new BestTimetoBuyandSellStockII();

    @Test
    void maxProfit() {
        assertEquals(7, solution.maxProfit(new int[]{7, 1, 5, 3, 6, 4}));
        assertEquals(4, solution.maxProfit(new int[]{1, 2, 3, 4, 5}));
        assertEquals(0, solution.maxProfit(new int[]{7, 6, 4, 3, 1}));
        assertEquals(7, solution.maxProfit(new int[]{6, 1, 3, 2, 4, 7}));
        assertEquals(2, solution.maxProfit(new int[]{2, 4, 1}));
        assertEquals(2, solution.maxProfit(new int[]{2, 1, 2, 0, 1}));
        assertEquals(2, solution.maxProfit(new int[]{2, 1, 2, 1, 0, 0, 1}));
    }
}