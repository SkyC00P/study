import done.ImplementQueueUsingStacks;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ImplementQueueUsingStacksTest {

    @Test
    void useQueue() {
        ImplementQueueUsingStacks.MyQueue queue = new ImplementQueueUsingStacks.MyQueue();

        queue.push(1);
        queue.push(2);
        assertEquals(1, queue.peek());
        assertEquals(1, queue.pop());
        assertFalse(queue.empty());
        assertEquals(2, queue.peek());
    }

}
