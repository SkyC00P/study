import java.util.ArrayList;
import java.util.List;

public class Subtract_theProduct_andSum_of_Digits_of_anInteger {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Subtract
     * the Product and Sum of Digits of an Integer. Memory Usage: 36.4 MB, less than
     * 12.50% of Java online submissions for Subtract the Product and Sum of Digits
     * of an Integer.
     */
    public int subtractProductAndSum(int n) {
        List<Integer> list = new ArrayList<>();
        int num = n;
        while (true) {
            int n2 = num % 10;
            num = num / 10;
            list.add(n2);
            if (num == 0) {
                break;
            }
        }
        int n1 = 0, n2 = 1;
        for (int i : list) {
            n1 = n1 + i;
            n2 = n2 * i;
        }
        return n2 - n1;
    }
}