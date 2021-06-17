package done;

public class NumberOfGoodPairs {
    /**
     * Runtime: 1 ms, faster than 82.15% of Java online submissions for Number of Good Pairs.
     * Memory Usage: 36.5 MB, less than 100.00% of Java online submissions for Number of Good Pairs.
     */
    public int numIdenticalPairs(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        NumberOfGoodPairs pairs = new NumberOfGoodPairs();
        System.out.println(4 == pairs.numIdenticalPairs(new int[]{1, 2, 3, 1, 1, 3}));
        System.out.println(6 == pairs.numIdenticalPairs(new int[]{1, 1, 1, 1}));
        System.out.println(0 == pairs.numIdenticalPairs(new int[]{1, 2, 3}));
    }
}
