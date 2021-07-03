import done.LongestPalindrome;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestPalindromeTest {

    LongestPalindrome test = new LongestPalindrome();

    @Test
    void _longestPalindrome() {
        assertEquals(7, test._longestPalindrome("abccccdd"));
    }
}
