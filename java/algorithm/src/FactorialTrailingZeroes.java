import utils.MathUtils;

public class FactorialTrailingZeroes {
    public int trailingZeroes(int n) {
        int num = MathUtils.factorial(n);
        if(num == 0) return 0;
        int count = 0;
        while (num % 10 == 0) {
            count += 1;
            num /= 10;
        }
        return count;
    }
}
