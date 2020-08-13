package todo;
/**
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * 
 * Given n, return the value of Tn.
 */
public class N_thTribonacciNumber {

    /**
     * 35 Time Limit Exceeded
     */
    public int tribonacci(final int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    }
}