package done;

public class AvailableCapturesForRook {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Available Captures for Rook.
     * Memory Usage: 36.2 MB, less than 83.19% of Java online submissions for Available Captures for Rook.
     */
    public int numRookCaptures(char[][] board) {
        int rx = 0, ry = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                    break;
                }
            }
        }
        int sum = 0;
        sum += lookForTop(board, rx, ry);
        sum += lookForBottom(board, rx, ry);
        sum += lookForLeft(board, rx, ry);
        sum += lookForRight(board, rx, ry);
        return sum;
    }

    private int lookForTop(char[][] board, int rx, int ry) {
        for (int i = ry + 1; i < 8; i++) {
            if (board[rx][i] == 'B') return 0;
            if (board[rx][i] == 'p') return 1;
        }
        return 0;
    }

    private int lookForBottom(char[][] board, int rx, int ry) {
        for (int i = ry - 1; i >= 0; i--) {
            if (board[rx][i] == 'B') return 0;
            if (board[rx][i] == 'p') return 1;
        }
        return 0;
    }

    private int lookForLeft(char[][] board, int rx, int ry) {
        for (int i = rx - 1; i >= 0; i--) {
            if (board[i][ry] == 'B') return 0;
            if (board[i][ry] == 'p') return 1;
        }
        return 0;
    }

    private int lookForRight(char[][] board, int rx, int ry) {
        for (int i = rx + 1; i < 8; i++) {
            if (board[i][ry] == 'B') return 0;
            if (board[i][ry] == 'p') return 1;
        }
        return 0;
    }
}
