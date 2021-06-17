package done;

public class MinimumCostToMoveChipsToTheSamePosition {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Minimum
     * Cost to Move Chips to The Same Position. Memory Usage: 37.1 MB, less than
     * 55.10% of Java online submissions for Minimum Cost to Move Chips to The Same
     * Position.
     */
    public int minCostToMoveChips(int[] chips) {
        int odd = 0;
        int event = 0;
        for (int i : chips) {
            if ((i & 1) == 1) {
                odd++;
            } else {
                event++;
            }
        }
        return Math.min(odd, event);
    }
}
