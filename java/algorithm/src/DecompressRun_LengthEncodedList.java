import java.util.ArrayList;
import java.util.List;

public class DecompressRun_LengthEncodedList {
    /**
     * Runtime: 6 ms, faster than 23.73% of Java online submissions for Decompress
     * Run-Length Encoded List. Memory Usage: 39.8 MB, less than 92.14% of Java
     * online submissions for Decompress Run-Length Encoded List.
     */
    public int[] decompressRLElist(final int[] nums) {
        final List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i += 2) {
            final int freq = nums[i];
            final int val = nums[i + 1];
            for (int j = 0; j < freq; j++) {
                list.add(val);
            }
        }
        return list.stream().mapToInt(Integer::valueOf).toArray();
    }
}
