public class MaximumNumber_ofBalloons {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Maximum Number of Balloons.
Memory Usage: 37.9 MB, less than 85.26% of Java online submissions for Maximum Number of Balloons.
     */
    // balloon x(b + a + 2l + 2o + n) ==> 求取最大公约数
    public int maxNumberOfBalloons(String text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (char ch : text.toCharArray()) {
            switch (ch) {
                case 'b':
                    b++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'l':
                    l++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'n':
                    n++;
                    break;
            }
        }
        return findMin(b, a, l / 2, o / 2, n);
    }

    private int findMin(int... nums) {
        int min = nums[0];
        for (int i : nums) {
            if (i == 0)
                return 0;
            if (i < min) {
                min = i;
            }
        }
        return min;
    }
}