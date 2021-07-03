import done.NimGame;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NimGameTest {

    NimGame solution = new NimGame();

    @Test
    void canWinNim() {
        assertFalse(solution.canWinNim(4));
    }
}
