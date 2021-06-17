package done;

public class Valid_Perfect_Square {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Valid Perfect Square.
     * Memory Usage: 31.9 MB, less than 44.88% of Java online submissions for Valid Perfect Square.
     */
    public boolean isPerfectSquare(int num) {
        return isPerfectSquare(num, 1, num);
    }

    private boolean isPerfectSquare(int num, long left, long right) {
        if (right - left < 1) return (right * right == num) || (left * left == num);
        long mid = (left + right) / 2;
        long n = mid * mid;
        if (n == num) return true;
        return n > num ? isPerfectSquare(num, left, mid - 1) : isPerfectSquare(num, mid + 1, right);
    }

    public static void main(String[] args) {
        Valid_Perfect_Square solution = new Valid_Perfect_Square();
        System.out.println(solution.isPerfectSquare(4));
        System.out.println(solution.isPerfectSquare(1));
        System.out.println(solution.isPerfectSquare(17));
        System.out.println(solution.isPerfectSquare(18));
        System.out.println(solution.isPerfectSquare(2147483647));
        System.out.println(solution.isPerfectSquare(598));
    }
}
