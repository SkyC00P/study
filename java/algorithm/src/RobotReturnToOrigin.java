public class RobotReturnToOrigin {
    /**
     * Runtime: 5 ms, faster than 69.92% of Java online submissions for Robot Return to Origin.
     * Memory Usage: 39.9 MB, less than 9.75% of Java online submissions for Robot Return to Origin.
     */
    public boolean judgeCircle(String moves) {
        int h = 0, v = 0;
        if (moves == null || moves.isEmpty()) {
            return true;
        }
        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'L':
                    h = h - 1;
                    break;
                case 'R':
                    h = h + 1;
                    break;
                case 'U':
                    v = v + 1;
                    break;
                case 'D':
                    v = v - 1;
                    break;
            }
        }
        return h == 0 && v == 0;
    }

    public static void main(String[] args) {
        RobotReturnToOrigin origin = new RobotReturnToOrigin();
        System.out.println(origin.judgeCircle("UD"));
        System.out.println(origin.judgeCircle("LL"));
    }
}
