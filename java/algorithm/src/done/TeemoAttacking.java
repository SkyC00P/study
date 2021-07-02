package done;

import java.util.HashSet;
import java.util.Set;

public class TeemoAttacking {
    // [t, t + duration - 1]

    /**
     * Runtime: 2 ms, faster than 54.42% of Java online submissions for Teemo Attacking.
     * Memory Usage: 40.9 MB, less than 59.27% of Java online submissions for Teemo Attacking.
     */
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int count = 0;
        if (timeSeries.length == 1) {
            return duration;
        }
        for (int i = 0; i < timeSeries.length; i++) {
            int is = timeSeries[i];
            int ie = is + duration - 1;

            count += ie - is + 1;

            if (i + 1 < timeSeries.length) {
                int in = timeSeries[i + 1];
                if (ie >= in) count = count - (ie - in + 1);
            }
        }
        return count;
    }

    /**
     * Time Limit Exceeded
     */
    public int findPoisonedDuration_fail(int[] timeSeries, int duration) {
        Set<Integer> sec = new HashSet<>();
        for (int time : timeSeries) {
            int end = time + duration - 1;
            for (int i = time; i <= end; i++) {
                sec.add(i);
            }
        }
        return sec.size();
    }
}
