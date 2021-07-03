import done.First_Unique_Character_in_a_String;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class First_Unique_Character_in_a_StringTest {

    First_Unique_Character_in_a_String solution = new First_Unique_Character_in_a_String();

    @Test
    void firstUniqChar() {
        int i = solution.firstUniqChar("leetcode");
        assertEquals(0, i);
        assertEquals(2, solution.firstUniqChar("loveleetcode"));
    }

    @Test
    void firstUniqChar1(){
        int i = solution.firstUniqChar1("leetcode");
        assertEquals(0, i);
        assertEquals(2, solution.firstUniqChar1("loveleetcode"));
    }
}
