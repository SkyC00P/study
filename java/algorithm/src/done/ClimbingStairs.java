package done;

public class ClimbingStairs {
    /**
     * 第一想法是动态规划
     * 第二想法是递归
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Climbing Stairs.
     * Memory Usage: 31.6 MB, less than 100.00% of Java online submissions for Climbing Stairs.
     */
    public int climbStairs(int n) {

        if (n == 1) return 1;
        if (n == 2) return 2;

        int[] d = new int[n];
        d[0] = 1;
        d[1] = 2;
        for (int i = 2; i < d.length; i++) {
            d[i] = d[i - 1] + d[i - 2];
        }
        return d[n - 1];
    }
}
