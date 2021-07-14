package done;

public class Minimum_Moves_to_Equal_Array_Elements {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Minimum Moves to Equal Array Elements.
     * Memory Usage: 39.4 MB, less than 59.15% of Java online submissions for Minimum Moves to Equal Array Elements.
     */
    public int minMoves(int[] nums) {
        int sum = 0;
        int min = Integer.MAX_VALUE;

        for (int num : nums) {
            sum += num;
            min = Math.min(min, num);
        }

        return sum - min * nums.length;
    }

    public static void main(String[] args) {
        // [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
        Minimum_Moves_to_Equal_Array_Elements test = new Minimum_Moves_to_Equal_Array_Elements();
        int i = test.minMoves(new int[]{1, 2, 3});
        System.out.println(i == 3);

        System.out.println(test.minMoves(new int[]{5, 6, 8, 8, 5}));
    }
}
