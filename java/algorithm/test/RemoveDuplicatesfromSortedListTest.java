import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesfromSortedListTest {

    RemoveDuplicatesfromSortedList solution = new RemoveDuplicatesfromSortedList();

    @Test
    void deleteDuplicates() {
        RemoveDuplicatesfromSortedList.ListNode node = create(new int[]{1, 1, 2});
        solution.deleteDuplicates(node);
        assertEquals("1->2->null", toString(node));
    }

    private String toString(RemoveDuplicatesfromSortedList.ListNode node) {
        StringBuilder sb = new StringBuilder();
        RemoveDuplicatesfromSortedList.ListNode cur = node;
        while(cur !=null){
            sb.append(cur.val).append("->");
            cur = cur.next;
        }
        sb.append("null");
        return sb.toString();
    }

    private RemoveDuplicatesfromSortedList.ListNode create(int[] arr) {
        RemoveDuplicatesfromSortedList.ListNode head = solution.new ListNode(arr[0]);
        RemoveDuplicatesfromSortedList.ListNode node = head;
        for (int i = 1; i < arr.length; i++) {
            if (node.next == null) {
                node.next = solution.new ListNode(arr[i]);
            }
            node = node.next;
        }
        return head;
    }
}