import java.util.Arrays;

public class HowManyNumbersAreSmallerThanTheCurrentNumber {
    /**
     * Runtime: 17 ms, faster than 14.31% of Java online submissions for How Many
     * Numbers Are Smaller Than the Current Number. Memory Usage: 41.3 MB, less than
     * 20.97% of Java online submissions for How Many Numbers Are Smaller Than the
     * Current Number.
     */
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] arr = new int[nums.length];
        Arrays.fill(arr, 0);
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (j != i && nums[j] < nums[i]) {
                    arr[i] = arr[i] + 1;
                }
            }
        }
        return arr;
    }
}
