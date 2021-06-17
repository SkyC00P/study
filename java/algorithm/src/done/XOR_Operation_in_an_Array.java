package done;

public class XOR_Operation_in_an_Array {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for XOR
     * Operation in an Array. Memory Usage: 37.9 MB, less than 34.29% of Java online
     * submissions for XOR Operation in an Array.
     */
    public int xorOperation(int n, int start) {
        int xor = start;
        for (int i = 1; i < n; i++) {
            xor ^= start + 2 * i;
        }
        return xor;
    }

    public static void main(String[] args) {
        XOR_Operation_in_an_Array main = new XOR_Operation_in_an_Array();
        System.out.println(main.xorOperation(5, 0) == 8);
        System.out.println(main.xorOperation(4, 3) == 8);
        System.out.println(main.xorOperation(1, 7) == 7);
        System.out.println(main.xorOperation(10, 5) == 2);
    }
}
