package done;

public class ComplementOfBase10Integer {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Complement of Base 10 Integer.
     * Memory Usage: 36.1 MB, less than 24.65% of Java online submissions for Complement of Base 10 Integer.
     */
    public int bitwiseComplement(int n) {
        return n == 0 ? 1 : ~n & Integer.highestOneBit(n) - 1;
    }

    public static void main(String[] args) {

        System.out.println(Integer.highestOneBit(5));
        System.out.println(Integer.lowestOneBit(5));
        System.out.println(5 ^ 0xf);
    }
}
