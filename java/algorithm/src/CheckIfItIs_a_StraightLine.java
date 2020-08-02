public class CheckIfItIs_a_StraightLine {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Check If It
     * Is a Straight Line. Memory Usage: 39 MB, less than 51.56% of Java online
     * submissions for Check If It Is a Straight Line.
     */
    public boolean checkStraightLine(int[][] coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1], x1 = coordinates[1][0], y1 = coordinates[1][1];
        int dx = x1 - x0, dy = y1 - y0;
        for (int[] co : coordinates) {
            int x = co[0], y = co[1];
            if (dx * (y - y1) != dy * (x - x1))
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        CheckIfItIs_a_StraightLine main = new CheckIfItIs_a_StraightLine();
        // true
        int[][] arr_1 = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 6 }, { 6, 7 } };
        System.out.println(main.checkStraightLine(arr_1));

        // false
        int[][] arr_2 = { { 1, 1 }, { 2, 2 }, { 3, 4 }, { 4, 5 }, { 5, 6 }, { 7, 7 } };
        System.out.println(main.checkStraightLine(arr_2));

        // ture
        int[][] arr_3 = { { 0, 0 }, { 0, 1 }, { 0, -1 } };
        System.out.println(main.checkStraightLine(arr_3));

        // true
        int[][] arr_4 = { { 2, 1 }, { 4, 2 }, { 6, 3 } };
        System.out.println(main.checkStraightLine(arr_4));

    }
}