package done;

public class ArrangingCoins {
    /**
     * Runtime: 9 ms, faster than 14.52% of Java online submissions for Arranging Coins.
     * Memory Usage: 33.6 MB, less than 5.46% of Java online submissions for Arranging Coins
     */
    public int arrangeCoins(int n) {
        int coins = n;
        int staircase = 1;
        int level = 0;
        while ((coins - staircase) >= 0) {
            coins = coins - staircase;
            staircase = staircase + 1;
            level++;
        }
        return level;
    }

    /**
     * Runtime: 60 ms, faster than 5.01% of Java online submissions for Arranging Coins.
     * Memory Usage: 33.5 MB, less than 5.46% of Java online submissions for Arranging Coins
     */
    public int arrangeCoins2(int n) {
        int i = 1;
        while (((Math.pow(i, 2) - i) / 2 + i) <= n) i++;
        return i - 1;
    }

    public static void main(String[] args) {
        ArrangingCoins test = new ArrangingCoins();
        System.out.println(test.arrangeCoins(5));
        System.out.println(test.arrangeCoins(8));
        System.out.println(Integer.MAX_VALUE);
    }
}
