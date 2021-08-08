package done;

import java.util.*;

public class FairCandySwap {
    /**
     * Runtime: 9 ms, faster than 71.43% of Java online submissions for Fair Candy Swap.
     * Memory Usage: 41 MB, less than 34.23% of Java online submissions for Fair Candy Swap.
     */
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int sum_1 = 0, sum_2 = 0;
        for (int n : aliceSizes) {
            sum_1 += n;
        }
        for (int n : bobSizes) {
            sum_2 += n;
        }
        return swap(sum_1 - sum_2, aliceSizes, bobSizes);
    }

    // s1 -x + y = s2 -y + x; s1- s2 = x - y -y +x = 2(x-y)
    private int[] swap(int diff, int[] a1, int[] a2) {
        Set<Integer> map = new HashSet<>();
        for (int item : a2) {
            map.add(item);
        }
        for (int x : a1) {
            int v = x - diff / 2;
            if (map.contains(v)) {
                return new int[]{x, v};
            }
        }
        return null;
    }

    public static void main(String[] args) {
        FairCandySwap main = new FairCandySwap();
        System.out.println(Arrays.toString(main.fairCandySwap(new int[]{1, 1}, new int[]{2, 2})));
    }
}
