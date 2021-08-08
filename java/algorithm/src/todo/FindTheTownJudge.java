package todo;

import java.util.HashSet;
import java.util.Set;

public class FindTheTownJudge {
    public int findJudge(int n, int[][] trust) {
        Set<Integer> person = new HashSet<>();
        for (int i = 1; i < n + 1; i++) {
            person.add(i);
        }
        Set<Integer> set = new HashSet<>();
        for (int[] t : trust) {
            person.remove(t[0]);
            set.add(t[1]);
        }
        if (person.size() == 1 && set.size() == 1) {
            int judge = person.iterator().next();
            int trust_judge = set.iterator().next();

            return judge == trust_judge ? judge : -1;
        } else {
            return -1;
        }
    }
}
