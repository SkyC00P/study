package done;

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Input: 123 Output: 321
 *
 * Input: -123 Output: -321
 *
 * Input: 120 Output: 21
 */
public class ReverseInteger {

    /**
     * Runtime: 17 ms, faster than 51.21% of Java online submissions for Reverse Integer.
     * Memory Usage: 37.8 MB, less than 90.55% of Java online submissions for Reverse Integer.
     */
    public int reverse(int x) {
        if(x == 0) return 0;
        StringBuilder sb = new StringBuilder(Integer.toString(x));
        try {
            return x > 0 ? Integer.parseInt(sb.reverse().toString()) : Integer.parseInt("-" + sb.reverse().deleteCharAt(sb.length()-1).toString());
        }catch (NumberFormatException E){
            return 0;
        }
    }

    public static void main(String[] args) {
        ReverseInteger solution = new ReverseInteger();
        System.out.println(solution.reverse(123) == 321);
        System.out.println(solution.reverse(-123) == -321);
        System.out.println(solution.reverse(120) == 21);
        System.out.println(solution.reverse(-0) == 0);
    }
}
