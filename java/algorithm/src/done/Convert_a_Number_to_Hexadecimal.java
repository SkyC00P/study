package done;

public class Convert_a_Number_to_Hexadecimal {

    final static char[] hex = new char[]{
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'a', 'b', 'c', 'd', 'e', 'f'
    };

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Convert a Number to Hexadecimal.
     * Memory Usage: 33.9 MB, less than 100.00% of Java online submissions for Convert a Number to Hexadecimal
     */
    public String toHex(int num) {
        if (num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        for (int i = 28; i >= 0; i -= 4) {
            char ch = hex[num >> i & 0xf];
            if (sb.length() != 0 || ch != '0') {
                sb.append(ch);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(Integer.toHexString(-1));
        System.out.println(Integer.toHexString(Integer.MAX_VALUE));
        System.out.println(hex[-1 >> 28 & 0xf]);
    }
}
