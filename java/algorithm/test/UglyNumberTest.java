import done.UglyNumber;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UglyNumberTest {

    UglyNumber solution = new UglyNumber();

    @Test
    void isUgly() {
        assertTrue(solution.isUgly(6));
        assertTrue(solution.isUgly(8));
        assertFalse(solution.isUgly(14));
        assertTrue(solution.isUgly(1));
        assertFalse(solution.isUgly(0));
        assertFalse(solution.isUgly(-6));
        assertFalse(solution.isUgly(-2147483648));
    }

    @Test
    void test() {
        int num = -2147483648;
        int[] arrs = new int[]{7, 11, 13, 17, 19, 23};
        for (int i = 0; i < arrs.length; i++) {
            if((num % arrs[i]) == 0){
                System.out.println(i);
                return;
            }
        }
    }
}
