import org.junit.jupiter.api.Test;
import todo.NthDigit;

import static org.junit.jupiter.api.Assertions.*;

class NthDigitTest {

    NthDigit digit = new NthDigit();

    @Test
    void findNthDigit() {
        assertEquals(3, digit.findNthDigit(3));
        assertEquals(0, digit.findNthDigit(11));
        assertEquals(2, digit.findNthDigit(2147483647));
    }

    public static void main(String[] args) {
        int n = 100;
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(i);
        }
        for (int i = 1; i <= sb.length(); i++) {
            System.out.println("i:" + i + "=" + sb.charAt(i - 1));
        }
    }
}