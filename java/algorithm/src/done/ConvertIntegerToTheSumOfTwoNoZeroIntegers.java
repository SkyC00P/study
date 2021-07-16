package done;

import java.util.Arrays;
import java.util.Stack;

public class ConvertIntegerToTheSumOfTwoNoZeroIntegers {
    /**
     * Runtime: 6 ms, faster than 8.16% of Java online submissions for Convert Integer to the Sum of Two No-Zero Integers.
     * Memory Usage: 37.5 MB, less than 22.11% of Java online submissions for Convert Integer to the Sum of Two No-Zero Integers.
     */
    public int[] getNoZeroIntegers(int n) {
        String sn = n + "";
        Stack<Character> n1 = new Stack<>();
        boolean borrow = false;
        for (int i = sn.length() - 1; i >= 0; i--) {
            char ch = sn.charAt(i);
            if (borrow) {
                switch (ch) {
                    case '0':
                    case '2':
                        if (i != 0)
                            n1.push('2');
                        borrow = true;
                        break;
                    case '1':
                        if (i != 0) {
                            n1.push('2');
                            borrow = true;
                        }
                        break;
                    default:
                        n1.push('1');
                        borrow = false;
                }
            } else {
                switch (ch) {
                    case '0':
                    case '1':
                        if (i != 0)
                            n1.push('2');
                        borrow = true;
                        break;
                    default:
                        n1.push('1');
                        borrow = false;
                }
            }
        }
        int[] arr = new int[2];
        arr[0] = toNum(n1);
        arr[1] = n - arr[0];
        return arr;
    }

    private int toNum(Stack<Character> n1) {
        StringBuilder sb = new StringBuilder();
        while (!n1.isEmpty()) {
            sb.append(n1.pop());
        }
        return Integer.parseInt(sb.toString());
    }

    public static void main(String[] args) {
        ConvertIntegerToTheSumOfTwoNoZeroIntegers main = new ConvertIntegerToTheSumOfTwoNoZeroIntegers();
        int[] arr = new int[]{214, 2, 11, 10000, 69, 1010, 19};
        for (int i : arr) {
            int[] ar = main.getNoZeroIntegers(i);
            System.out.println(Arrays.toString(ar));
            System.out.println((ar[0] + ar[1]) == i);
        }
    }
}
