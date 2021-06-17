package done;

public class NumberComplement {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Number Complement.
     * Memory Usage: 33 MB, less than 5.26% of Java online submissions for Number Complement.
     */
    public int findComplement(int num) {
        for (int i = Integer.SIZE - 1; i >= 0; i--) {
            if ((num >>> i & 1) == 1) {
                int move = Integer.SIZE - 1 - i;
                return (~(num << move)) >>> move;
            }
        }
        return 1;
    }

    public static void main(String[] args) {
        NumberComplement test = new NumberComplement();
        int i = test.findComplement(5);
        System.out.println(i == 2);
        System.out.println(Integer.MAX_VALUE >>> 31);
        System.out.println(Integer.MAX_VALUE >>> 30);
        System.out.println(Integer.MAX_VALUE >>> 29);
        System.out.println(Integer.MAX_VALUE >>> 28);
        System.out.println(5 << 29);
        System.out.println(~(5 << 29));
        System.out.println(~(5 << 29));
    }
}
