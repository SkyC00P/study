import datastruct.ListNode;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import static org.junit.jupiter.api.Assertions.*;

class ReverseLinkedListTest {

    ReverseLinkedList solution = new ReverseLinkedList();

    //Input: 1->2->3->4->5->NULL
    //Output: 5->4->3->2->1->NULL
    @Test
    void reverseList() {
        ListNode node = ListUtils.createList(new int[]{1, 2, 3, 4, 5}, -1);
        ListNode real = ListUtils.createList(new int[]{5, 4, 3, 2, 1}, -1);
        ListNode reverseNode = solution.reverseList(node);
        assertEquals(ListUtils.toString(real), ListUtils.toString(reverseNode));
    }
}