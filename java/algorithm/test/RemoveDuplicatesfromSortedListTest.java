import datastruct.ListNode;
import done.RemoveDuplicatesfromSortedList;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesfromSortedListTest {

    RemoveDuplicatesfromSortedList solution = new RemoveDuplicatesfromSortedList();

    @Test
    void deleteDuplicates() {
        ListNode node = create(new int[]{1, 1, 2});
        solution.deleteDuplicates(node);
        assertEquals("1->2->null", toString(node));
    }

    private String toString(ListNode node) {
        StringBuilder sb = new StringBuilder();
        ListNode cur = node;
        while(cur !=null){
            sb.append(cur.val).append("->");
            cur = cur.next;
        }
        sb.append("null");
        return sb.toString();
    }

    private ListNode create(int[] arr) {
        ListNode head = new ListNode(arr[0]);
        ListNode node = head;
        for (int i = 1; i < arr.length; i++) {
            if (node.next == null) {
                node.next = new ListNode(arr[i]);
            }
            node = node.next;
        }
        return head;
    }
}
