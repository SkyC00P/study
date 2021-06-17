package done;

import java.util.HashSet;
import java.util.Set;

// 2 20 21 22
// 1 10 11 12
// 0 00 01 02
//   0  1  2
public class FindWinnerOnATicTacToeGame {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Find Winner
     * on a Tic Tac Toe Game. Memory Usage: 37.1 MB, less than 57.01% of Java online
     * submissions for Find Winner on a Tic Tac Toe Game.
     */
    public String tictactoe(int[][] moves) {
        if (moves.length < 5) {
            return "Pending";
        }
        int a = 0, b = 0;
        int len = moves.length;
        int[] p_end = moves[len - 1];
        boolean isA = (len & 1) == 1;
        Set<int[]> line_1 = new HashSet<>();
        Set<int[]> line_2 = new HashSet<>();
        for (int i = len - 3; i >= 0; i -= 2) {
            int[] p = moves[i];
            if (p[0] == p_end[0]) {
                a += 1;
            }
            if (p[1] == p_end[1]) {
                b += 1;
            }
            if (p[0] - p[1] == 0) {
                if (p[0] == 1) {
                    line_2.add(p);
                }
                line_1.add(p);
            } else if (Math.abs(p[0] - p[1]) == 2) {
                line_2.add(p);
            }
        }
        if (p_end[0] - p_end[1] == 0) {
            line_1.add(p_end);
            if (p_end[0] == 1) {
                line_2.add(p_end);
            }
        } else if (Math.abs(p_end[0] - p_end[1]) == 2) {
            line_2.add(p_end);
        }
        return a == 2 || b == 2 || (line_1.size() == 3 || line_2.size() == 3) ? (isA ? "A" : "B")
                : (len == 9 ? "Draw" : "Pending");
    }

    public static void main(String[] args) {
        FindWinnerOnATicTacToeGame main = new FindWinnerOnATicTacToeGame();

        // test "A"
        int[][] t3 = { { 0, 2 }, { 1, 0 }, { 2, 2 }, { 1, 2 }, { 2, 0 }, { 0, 0 }, { 0, 1 }, { 2, 1 }, { 1, 1 } };
        System.out.println(main.tictactoe(t3));

        // test "Pending"
        int[][] t2 = { { 0, 0 }, { 0, 1 }, { 2, 0 }, { 1, 0 }, { 2, 1 }, { 2, 2 }, { 1, 1 } };
        System.out.println(main.tictactoe(t2));

        // test "Pending"
        int[][] t1 = { { 2, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 }, { 1, 2 }, { 1, 0 } };
        System.out.println(main.tictactoe(t1));

        // A
        int[][] moves = { { 0, 0 }, { 2, 0 }, { 1, 1 }, { 2, 1 }, { 2, 2 } };
        System.out.println(main.tictactoe(moves));

        // B
        int[][] moves_1 = { { 0, 0 }, { 1, 1 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 2, 0 } };
        System.out.println(main.tictactoe(moves_1));

        // Draw
        int[][] moves_2 = { { 0, 0 }, { 1, 1 }, { 2, 0 }, { 1, 0 }, { 1, 2 }, { 2, 1 }, { 0, 1 }, { 0, 2 }, { 2, 2 } };
        System.out.println(main.tictactoe(moves_2));

        // Pending
        int[][] moves_3 = { { 0, 0 }, { 1, 1 } };
        System.out.println(main.tictactoe(moves_3));

    }
}
