import datastruct.ListNode;
import done.LinkedListCycle;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import static org.junit.jupiter.api.Assertions.*;

class LinkedListCycleTest {

    LinkedListCycle solution = new LinkedListCycle();

    @Test
    void hasCycle() {
        ListNode node = ListUtils.createList(new int[]{3, 2, 0, 4}, 1);
        ListUtils.print(node, 5);
        assertTrue(solution.hasCycle(node));

        node = ListUtils.createList(new int[]{1, 2}, 0);
        ListUtils.print(node, 3);
        assertTrue(solution.hasCycle(node));

        node = ListUtils.createList(new int[]{1}, -1);
        ListUtils.print(node, 1);
        assertFalse(solution.hasCycle(node));

        node = ListUtils.createList(new int[]{}, -1);
        assertFalse(solution.hasCycle(node));
    }

    @Test
    void hasCycle1() {
        ListNode node = ListUtils.createList(new int[]{3, 2, 0, 4}, 1);
        ListUtils.print(node, 5);
        assertTrue(solution.hasCycle1(node));

        node = ListUtils.createList(new int[]{1, 2}, 0);
        ListUtils.print(node, 3);
        assertTrue(solution.hasCycle1(node));

        node = ListUtils.createList(new int[]{1}, -1);
        ListUtils.print(node, 1);
        assertFalse(solution.hasCycle1(node));

        node = ListUtils.createList(new int[]{}, -1);
        assertFalse(solution.hasCycle1(node));
    }
}
