package done;

public class RotatedDigits {
    /**
     * Runtime: 33 ms, faster than 8.23% of Java online submissions for Rotated
     * Digits. Memory Usage: 46.6 MB, less than 7.87% of Java online submissions for
     * Rotated Digits.
     */
    public int rotatedDigits(int N) {
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            if (isValid(i)) {
                System.out.println(i);
                sum++;
            }
        }
        return sum;
    }

    private boolean isValid(int i) {
        int num = i;
        StringBuilder sb = new StringBuilder();
        do {
            int n = num % 10;
            switch (n) {
                case 0:
                case 1:
                case 8:
                    sb.append(n);
                    break;
                case 2:
                    sb.append(5);
                    break;
                case 5:
                    sb.append(2);
                    break;
                case 6:
                    sb.append(9);
                    break;
                case 9:
                    sb.append(6);
                    break;
                default:
                    return false;
            }
            num = num / 10;
        } while (num != 0);

        return Integer.parseInt(sb.reverse().toString()) != i;
    }

    public static void main(String[] args) {
        RotatedDigits digits = new RotatedDigits();
        System.out.println(digits.rotatedDigits(10));
    }
}
