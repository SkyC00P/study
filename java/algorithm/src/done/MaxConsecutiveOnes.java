package done;

public class MaxConsecutiveOnes {
    /**
     * Runtime: 2 ms, faster than 99.70% of Java online submissions for Max Consecutive Ones.
     * Memory Usage: 38.6 MB, less than 100.00% of Java online submissions for Max Consecutive Ones.
     */
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int n = 0;
        for (int read = 0; read < nums.length; read++) {
            if (nums[read] == 1) {
                n++;
            } else {
                if (n > max) {
                    max = n;
                }
                n = 0;
            }
        }
        return n > max ? n : max;
    }

    public static void main(String[] args) {
        MaxConsecutiveOnes test = new MaxConsecutiveOnes();
        System.out.println(3 == test.findMaxConsecutiveOnes(new int[]{1, 1, 0, 1, 1, 1}));
    }
}
