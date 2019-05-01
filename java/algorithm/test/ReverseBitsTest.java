import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseBitsTest {

    ReverseBits solution = new ReverseBits();

    @Test
    void reverseBits() {
        // 00000010100101000001111010011100 -> 00111001011110000010100101000000
        assertEquals(964176192, solution.reverseBits(43261596));
        // 11111111111111111111111111111101 -> 10111111111111111111111111111111
        assertEquals(-3, solution.reverseBits(-1073741825));
    }

    @Test
    void test() {
        System.out.println(0<<1);
    }
}