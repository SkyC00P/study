import done.BestTimetoBuyandSellStock;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BestTimetoBuyandSellStockTest {

    BestTimetoBuyandSellStock solution = new BestTimetoBuyandSellStock();

    @Test
    void maxProfit() {
        assertEquals(5, solution.maxProfit(new int[]{7,1,5,3,6,4}));
        assertEquals(0, solution.maxProfit(new int[]{7,6,4,3,1}));

        assertEquals(5, solution.maxProfit_1(new int[]{7,1,5,3,6,4}));
        assertEquals(0, solution.maxProfit_1(new int[]{7,6,4,3,1}));
        assertEquals(1, solution.maxProfit_1(new int[]{7,3,4,2,1}));
    }
}
