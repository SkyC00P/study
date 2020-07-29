
public class FibonacciNumber {
    /**
     * Runtime: 10 ms, faster than 14.06% of Java online submissions for Fibonacci Number.
     * Memory Usage: 37.7 MB, less than 7.79% of Java online submissions for Fibonacci Number
     */
    public int fib(int N) {
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        return fib(N - 1) + fib(N - 2);
    }
}
