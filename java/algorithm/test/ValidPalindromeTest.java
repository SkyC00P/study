import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidPalindromeTest {

    ValidPalindrome solution = new ValidPalindrome();

    @Test
    void isPalindrome() {
        assertTrue(solution.isPalindrome(""));
        assertTrue(solution.isPalindrome("A man, a plan, a canal: Panama"));
        assertFalse(solution.isPalindrome("race a car"));
        assertFalse(solution.isPalindrome("0P"));
    }

    @Test
    void test(){
        System.out.println(Character.isAlphabetic('a'));
        System.out.println(Character.isAlphabetic('B'));
        System.out.println(Character.isAlphabetic('1'));
        assertTrue(Character.isLetterOrDigit('a'));
        assertTrue(Character.isLetterOrDigit('1'));
        System.out.println(Character.isAlphabetic(' '));
        System.out.println(Character.isAlphabetic(','));
    }
}