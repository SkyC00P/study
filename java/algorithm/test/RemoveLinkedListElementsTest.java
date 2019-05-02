import datastruct.ListNode;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import static org.junit.jupiter.api.Assertions.*;

class RemoveLinkedListElementsTest {

    RemoveLinkedListElements solution = new RemoveLinkedListElements();

    @Test
    void removeElements() {
        ListNode node = ListUtils.createList(new int[]{1, 2, 6, 3, 4, 5, 6}, -1);
        ListUtils.print(node);
        ListNode real = ListUtils.createList(new int[]{1, 2, 3, 4, 5}, -1);
        ListNode newNode = solution.removeElements(node, 6);
        assertEquals(ListUtils.toString(real), ListUtils.toString(newNode));
    }

    @Test
    void removeHead() {
        ListNode node = ListUtils.createList(new int[]{1, 2, 6}, -1);
        ListUtils.print(node);
        ListNode real = ListUtils.createList(new int[]{2, 6}, -1);
        ListNode newNode = solution.removeElements(node, 1);
        assertEquals(ListUtils.toString(real), ListUtils.toString(newNode));
    }

    @Test
    void removeNull() {
        ListNode node = ListUtils.createList(new int[]{1, 1, 1}, -1);
        ListUtils.print(node);
        ListNode newNode = solution.removeElements(node, 1);
        assertEquals("Null", ListUtils.toString(newNode));
    }
    @Test
    void removeReapt(){
        ListNode node = ListUtils.createList(new int[]{1,2,2,1}, -1);
        ListUtils.print(node);
        ListNode real = ListUtils.createList(new int[]{1,1}, -1);
        ListNode newNode = solution.removeElements(node, 2);
        assertEquals(ListUtils.toString(real), ListUtils.toString(newNode));
    }
}