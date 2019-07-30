import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Number_of_Equivalent_Domino_Pairs {
    /**
     * Time Limit Exceeded
     */
    public int numEquivDominoPairs_fail(int[][] dominoes) {
        int len = 0;
        for (int i = 0; i < dominoes.length; i++) {
            for (int j = i + 1; j < dominoes.length; j++) {
                if (hasEquiv(dominoes, i, j)) len++;
            }
        }
        return len;
    }

    /**
     * Runtime: 20 ms, faster than 25.37% of Java online submissions for Number of Equivalent Domino Pairs.
     * Memory Usage: 57.4 MB, less than 100.00% of Java online submissions for Number of Equivalent Domino Pairs
     */
    public int numEquivDominoPairs(int[][] dominoes) {
        int len = 0;
        Map<String, Set<Integer>> map = new HashMap<>();
        for (int i = 0; i < dominoes.length; i++) {
            int[] arr = dominoes[i];
            String key = arr[0] >= arr[1] ? arr[0] + "" + arr[1] : arr[1] + "" + arr[0];
            if (map.containsKey(key)) {
                Set<Integer> set = map.get(key);
                set.add(i);
            } else {
                Set<Integer> set = new HashSet<>();
                set.add(i);
                map.put(key, set);
            }
        }

        for (Set<Integer> set : map.values()) {
            int size = set.size();
            if (size == 1) continue;
            if (size == 2) {len++; continue;}
            len += (Math.pow(size, 2) - size) / 2;
        }
        return len;
    }

    private boolean hasEquiv(int[][] dominoes, int i, int j) {
        int[] a = dominoes[i];
        int[] b = dominoes[j];
        return (a[0] == b[0] && a[1] == b[1]) || (a[0] == b[1] && a[1] == b[0]);
    }

    public static void main(String[] args) {
        Number_of_Equivalent_Domino_Pairs test = new Number_of_Equivalent_Domino_Pairs();
        int[][] arrs = new int[][]{
                new int[]{1, 2},
                new int[]{2, 1},
                new int[]{3, 4},
                new int[]{5, 6}
        };
        int i = test.numEquivDominoPairs(arrs);
        System.out.println(i);
    }
}
