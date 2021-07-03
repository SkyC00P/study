import done.ImplementStackUsingQueues;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ImplementStackUsingQueuesTest {

    @Test
    void useStack() {
        ImplementStackUsingQueues.MyStack stack = new ImplementStackUsingQueues.MyStack();

        stack.push(1);
        stack.push(2);

        assertEquals(2, stack.top());
        assertEquals(2, stack.pop());
        assertFalse(stack.empty());
    }
}
