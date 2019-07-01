import org.junit.jupiter.api.Test;

import java.util.ArrayDeque;
import java.util.Deque;

import static org.junit.jupiter.api.Assertions.*;

class WordPatternTest {

    WordPattern solution = new WordPattern();

    @Test
    void wordPattern() {
        assertTrue(solution.wordPattern("abba", "dog cat cat dog"));
        assertTrue(!solution.wordPattern("abba", "dog cat cat fish"));
        assertTrue(!solution.wordPattern("aaaa","dog cat cat dog" ));
        assertTrue(!solution.wordPattern("abba", "dog dog dog dog"));
    }

    @Test
    void test(){
        Deque<Integer> deque = new ArrayDeque<>();
        deque.push(1);
        deque.push(2);
        System.out.println(deque.getFirst());
        //System.out.println(deque.poll());
        System.out.println(deque.remove());
        System.out.println(deque.offer(3));
        System.out.println(deque);
        System.out.println(deque.remove());
    }
}