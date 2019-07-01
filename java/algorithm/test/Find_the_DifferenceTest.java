import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Find_the_DifferenceTest {

    Find_the_Difference solution = new Find_the_Difference();

    @Test
    void findTheDifference() {
        assertEquals('e', solution.findTheDifference("abcd", "abcde"));
    }

    @Test
    void findTheDifference1() {
        assertEquals('e', solution.findTheDifference1("abcd", "abcde"));
    }
}