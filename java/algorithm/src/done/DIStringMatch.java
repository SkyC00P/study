package done;

public class DIStringMatch {
    /**
     * 对撞双指针
     * Runtime: 2 ms, faster than 95.19% of Java online submissions for DI String Match.
     * Memory Usage: 40.5 MB, less than 28.85% of Java online submissions for DI String Match.
     */
    public int[] diStringMatch(String s) {
        int n = s.length(), l = 0, r = n;
        int[] res = new int[n + 1];
        for (int i = 0, idx = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (ch == 'I') {
                res[idx++] = l++;
            } else {
                res[idx++] = r--;
            }
        }

        res[n] = l;
        return res;
    }
}
