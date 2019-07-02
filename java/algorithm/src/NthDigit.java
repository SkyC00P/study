public class NthDigit {
    public int findNthDigit(int n) {
        return n;
    }

    /**
     * Memory Limit Exceeded
     */
    public int findNthDigit_fail(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(i);
        }
        return Integer.parseInt(sb.charAt(n - 1) + "");
    }

    public static void main(String[] args) {
        NthDigit digit = new NthDigit();
        System.out.println(digit.findNthDigit(10000000));
    }
}
