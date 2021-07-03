import done.Sqrt;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SqrtTest {

    Sqrt sqrt = new Sqrt();

    @Test
    void mySqrt() {
        assertEquals(2, sqrt.mySqrt(4));
        assertEquals(2, sqrt.mySqrt(8));
        assertEquals(2, sqrt.mySqrt(6));
        assertEquals(46340, sqrt.mySqrt(2147483647));
    }

    @Test
    void mySqrt_0() {
        assertEquals(2, sqrt.mySqrt_0(4));
        assertEquals(2, sqrt.mySqrt_0(8));
        assertEquals(2, sqrt.mySqrt_0(6));
        assertEquals(46340, sqrt.mySqrt_0(2147483647));
    }
}
