import done.StringCompression;
import org.junit.jupiter.api.Test;
import utils.ArrayUtils;

import static org.junit.jupiter.api.Assertions.*;


class StringCompressionTest {

    StringCompression test = new StringCompression();

    @Test
    void compress() {
        char[] chs = null;

        chs = new char[]{'a'};
        assertEquals(1, test.compress(chs));
        assertTrue(ArrayUtils.equalsFromIndex(new char[]{'a'}, chs, 1));

        chs = new char[]{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        assertEquals(6, test.compress(chs));
        assertTrue(ArrayUtils.equalsFromIndex(new char[]{'a', '2', 'b', '2', 'c', '3'}, chs, 6));

        chs = new char[]{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        assertEquals(4, test.compress(chs));
        assertTrue(ArrayUtils.equalsFromIndex(new char[]{'a', 'b', '1', '2'}, chs, 4));

        chs = new char[]{'a', 'a', 'a', 'b', 'b', 'a', 'a'};
        assertEquals(6, test.compress(chs));
        assertTrue(ArrayUtils.equalsFromIndex(new char[]{'a', '3', 'b', '2', 'a', '2'}, chs, 6));

        chs = new char[]{'a', 'a', 'a', 'a', 'a', 'b'};
        assertEquals(3, test.compress(chs));
        assertTrue(ArrayUtils.equalsFromIndex(new char[]{'a', '5', 'b'}, chs, 3));

    }
}
