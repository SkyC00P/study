public class NimGame {
    // 1,2,3 my first
    public boolean canWinNim(int n) {
        if (n <= 3) return true;
        if (n == 4) return false;

        // n-1 > 3, n-2 > 3, n-3 > 3 maybe win
        // but n-1 <= 3, n-2<=3, n-3<=3 must lost
        // 8 的递减速度

        return true;
    }
}
