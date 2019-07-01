/**
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */
public class MoveZeroes {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Move Zeroes.
     * Memory Usage: 36.9 MB, less than 96.59% of Java online submissions for Move Zeroes.
     */
    public void moveZeroes(int[] nums) {
        int shitf = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                shitf++;
            } else {
                nums[i - shitf] = nums[i];
            }
        }

        int i = nums.length - 1;
        while (shitf != 0) {
            nums[i--] = 0;
            shitf--;
        }
    }
}
