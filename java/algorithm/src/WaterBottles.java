public class WaterBottles {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Water Bottles.
     * Memory Usage: 36 MB, less than 100.00% of Java online submissions for Water Bottles.
     */
    public int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return numBottles;
        }
        if (numBottles == numExchange) {
            return numBottles + 1;
        }

        int max = numBottles;
        while (true) {
            int exchange = numBottles / numExchange;
            int remain = numBottles % numExchange;
            max += exchange;
            if (exchange + remain < numExchange) {
                return max;
            }
            numBottles = exchange + remain;
        }
    }

    public static void main(String[] args) {
        WaterBottles waterBottles = new WaterBottles();
        System.out.println(waterBottles.numWaterBottles(15, 4));
        if (waterBottles.numWaterBottles(9, 3) != 13) throw new AssertionError();
        if (waterBottles.numWaterBottles(15, 4) != 19) throw new AssertionError();
        if (waterBottles.numWaterBottles(5, 5) != 6) throw new AssertionError();
        if (waterBottles.numWaterBottles(2, 3) != 2) throw new AssertionError();
    }
}
