package done;

public class Sqrt {

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for done.Sqrt(x).
     * Memory Usage: 32.5 MB, less than 100.00% of Java online submissions for done.Sqrt(x).
     */
    public int mySqrt(int x) {
        return (int) Math.sqrt(x);
    }

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for done.Sqrt(x).
     * Memory Usage: 32.4 MB, less than 100.00% of Java online submissions for done.Sqrt(x).
     */
    public int mySqrt_0(int x) {
        long a = x;
        while (a * a > x) {
            a = (a + x / a) / 2;
        }
        return (int) a;
    }
}
