package done;

public class LemonadeChange {
    /**
     * Runtime: 2 ms, faster than 64.21% of Java online submissions for Lemonade Change.
     * Memory Usage: 49.6 MB, less than 5.35% of Java online submissions for Lemonade Change.
     */
    public boolean lemonadeChange(int[] bills) {
        int[] money = new int[3];
        for (int bill : bills) {
            if (bill == 5) {
                money[0] += 5;
            } else if (bill == 10) {
                money[0] -= 5;
                money[1] += 10;
                if (money[0] < 0) return false;
            } else if (bill == 20) {
                money[2] += 20;
                if (money[0] >= 5 && money[1] >= 10) {
                    money[0] -= 5;
                    money[1] -= 10;
                } else if (money[0] >= 15) {
                    money[0] -= 15;
                } else {
                    return false;
                }
                if (money[0] < 0 || money[1] < 0) return false;
            }
        }
        return true;
    }
}
