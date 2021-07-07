package done;

public class LongestContinuousIncreasingSubsequence {
    /**
     * Runtime: 4 ms, faster than 6.92% of Java online submissions for Longest Continuous Increasing Subsequence.
     * Memory Usage: 39.8 MB, less than 49.66% of Java online submissions for Longest Continuous Increasing Subsequence.
     */
    public int findLengthOfLCIS(int[] nums) {
        int max = -1;
        for (int i = 0; i < nums.length; i++) {
            int n = 0;
            for (int j = i; j < nums.length; j++) {
                if (j == nums.length - 1) {n++; break;}
                if (nums[j] < nums[j + 1]) {
                    n++;
                } else {
                    n++;
                    break;
                }
            }
            if (n > max) max = n;
        }
        return max == -1 ? 1 : max;
    }

    public static void main(String[] args) {
        LongestContinuousIncreasingSubsequence main = new LongestContinuousIncreasingSubsequence();
        System.out.println(main.findLengthOfLCIS(new int[]{1, 3, 5, 7}));
        // 1,3,5,4,7
        System.out.println(main.findLengthOfLCIS(new int[]{1, 3, 5, 4, 7}));
    }
}
