import done.IsomorphicStrings;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class IsomorphicStringsTest {

    IsomorphicStrings sulution = new IsomorphicStrings();

    @Test
    void isIsomorphic() {
        assertTrue(sulution.isIsomorphic("egg", "add"));
        assertFalse(sulution.isIsomorphic("foo", "bar"));
        assertTrue(sulution.isIsomorphic("paper", "title"));
    }
}
