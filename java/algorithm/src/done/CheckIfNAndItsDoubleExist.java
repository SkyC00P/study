package done;

import java.util.HashSet;
import java.util.Set;

public class CheckIfNAndItsDoubleExist {
    /**
     * Runtime: 2 ms, faster than 54.63% of Java online submissions for Check If N
     * and Its Double Exist. Memory Usage: 38.4 MB, less than 99.96% of Java online
     * submissions for Check If N and Its Double Exist.
     */
    public boolean checkIfExist(int[] arr) {
        int zero = 0;
        Set<Integer> set = new HashSet<>();
        for (int i : arr) {
            if (i == 0) {
                zero++;
            } else {
                set.add(i);
            }
        }
        if (zero >= 2)
            return true;
        for (int i : arr) {
            if (set.contains(i * 2)) {
                return true;
            }
        }
        return false;
    }
}
