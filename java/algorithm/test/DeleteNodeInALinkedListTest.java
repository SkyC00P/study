import datastruct.ListNode;
import done.DeleteNodeInALinkedList;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import static org.junit.jupiter.api.Assertions.*;

class DeleteNodeInALinkedListTest {

    DeleteNodeInALinkedList solution = new DeleteNodeInALinkedList();

    @Test
    void deleteNode() {
        ListNode node = ListUtils.createList(new int[]{4,5,1,9}, -1);
        ListNode fNode = ListUtils.findNode(node, 5);
        solution.deleteNode(fNode);
        assertEquals("4->1->9->null", ListUtils.toString(node));
    }
}
