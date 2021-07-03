import done.Reverse_Vowels_of_a_String;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Reverse_Vowels_of_a_StringTest {

    Reverse_Vowels_of_a_String solution = new Reverse_Vowels_of_a_String();

    @Test
    void reverseVowels() {
        assertEquals("holle", solution.reverseVowels("hello"));
        assertEquals("leotcede", solution.reverseVowels("leetcode"));
    }
}
