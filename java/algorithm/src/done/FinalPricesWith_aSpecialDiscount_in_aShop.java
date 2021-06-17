package done;

public class FinalPricesWith_aSpecialDiscount_in_aShop {
    /**
     * Runtime: 1 ms, faster than 99.47% of Java online submissions for Final Prices
     * With a Special Discount in a Shop. Memory Usage: 39.7 MB, less than 69.52% of
     * Java online submissions for Final Prices With a Special Discount in a Shop.
     */
    public int[] finalPrices(int[] prices) {
        for (int i = 0; i < prices.length; i++) {
            int price = prices[i];
            for (int j = i + 1; j < prices.length; j++) {
                if (prices[j] <= price) {
                    price -= prices[j];
                    break;
                }
            }
            prices[i] = price;
        }
        return prices;
    }
}
