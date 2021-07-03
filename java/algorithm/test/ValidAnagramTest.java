import done.ValidAnagram;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class ValidAnagramTest {

    ValidAnagram solution = new ValidAnagram();

    @Test
    void isAnagram() {
        assertTrue(solution.isAnagram("anagram", "nagaram"));
        assertFalse(solution.isAnagram("rat", "car"));
        assertFalse(solution.isAnagram("ab", "a"));
        assertFalse(solution.isAnagram("aa", "a"));
        assertFalse(solution.isAnagram("aacc", "ccac"));
    }

    @Test
    void lamba() {
        Map<Character, Integer> smap = new HashMap<>();
        Integer num = smap.merge('a', 1, (oldV, newV) -> oldV + 1);
        System.out.println(num);
        num = smap.merge('a', 1, (oldV, newV) -> {
            System.out.println(oldV + " " + newV);
            return oldV + 1;
        });
        System.out.println(num);
        System.out.println(smap.get('a'));

        num = smap.merge('a', 1, (oldV, newV) -> {
            System.out.println(oldV + " " + newV);
            return oldV + 1;
        });
        System.out.println(num);
        System.out.println(smap.get('a'));
    }
}
