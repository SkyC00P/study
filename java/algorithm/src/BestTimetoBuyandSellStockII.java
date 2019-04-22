public class BestTimetoBuyandSellStockII {

    /**
     * Runtime: 1 ms, faster than 80.57% of Java online submissions for Best Time to Buy and Sell Stock II.
     * Memory Usage: 38.8 MB, less than 48.89% of Java online submissions for Best Time to Buy and Sell Stock II.
     */
    public int maxProfit(int[] prices) {
        if (prices.length == 0 || prices.length == 1) {
            return 0;
        }
        int maxProfit = 0;

        for (int i = 0; i < prices.length; ) {
            int[] range = findIncreasingRange(prices, i);
            if (range == null) break;
            i = 1 + range[1];
            maxProfit += prices[range[1]] - prices[range[0]];
        }
        return maxProfit;
    }

    private int[] findIncreasingRange(int[] prices, int startIndex) {
        int min = -1;
        for (int i = startIndex + 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                min = i - 1;
                break;
            }
        }
        if (min == -1) {
            return null;
        }
        int max = -1;
        for (int i = min + 1; i < prices.length; i++) {
            if(prices[i] - prices[i-1] > 0){
                max = i;
            }else break;
        }
        return max == -1 ? null : new int[]{min, max};
    }
}
