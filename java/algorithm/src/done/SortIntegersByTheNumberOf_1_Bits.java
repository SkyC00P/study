package done;

import java.util.Arrays;
import java.util.Comparator;

public class SortIntegersByTheNumberOf_1_Bits {

    class Data {
        int index;
        int bitCount;
        int num;
    }

    /**
     * Runtime: 6 ms, faster than 88.66% of Java online submissions for Sort Integers by The Number of 1 Bits.
     * Memory Usage: 39.5 MB, less than 49.24% of Java online submissions for Sort Integers by The Number of 1 Bits.
     */
    public int[] sortByBits(int[] arr) {
        Data[] ds = new Data[arr.length];
        for (int i = 0; i < arr.length; i++) {
            Data d = new Data();
            d.index = i;
            d.num = arr[i];
            d.bitCount = Integer.bitCount(d.num);
            ds[i] = d;
        }
        Arrays.sort(ds, (o1, o2) -> {
            int i = o1.bitCount - o2.bitCount;
            return i == 0 ? o1.num - o2.num : i;
        });
        for (int i = 0; i < ds.length; i++) {
            arr[i] = ds[i].num;
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
        for (int i : arr) {
            System.out.println(Integer.bitCount(i));
        }
    }
}
