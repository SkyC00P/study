package done;

public class BestTimetoBuyandSellStock {

    /**
     * 暴力解法
     * Runtime: 93 ms, faster than 15.19% of Java online submissions for Best Time to Buy and Sell Stock.
     * Memory Usage: 39.7 MB, less than 21.66% of Java online submissions for Best Time to Buy and Sell Stock.
     */
    public int maxProfit(int[] prices) {
        int max = 0;
        for (int i = 0; i < prices.length; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > max) {
                    max = profit;
                }
            }
        }
        return max;
    }

    /**
     * Runtime: 1 ms, faster than 80.81% of Java online submissions for Best Time to Buy and Sell Stock.
     * Memory Usage: 40.4 MB, less than 5.07% of Java online submissions for Best Time to Buy and Sell Stock.
     */
    public int maxProfit_1(int prices[]) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
}
