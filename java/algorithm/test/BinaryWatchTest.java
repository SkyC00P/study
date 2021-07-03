import done.BinaryWatch;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryWatchTest {

    BinaryWatch watch = new BinaryWatch();

    @Test
    void readBinaryWatch() {
        List<String> list = watch.readBinaryWatch(1);
        List<String> real = ListUtils.createList(new String[]{"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"});
        assertTrue(ListUtils.equalIgnoreOrder(list, real));
    }

}
