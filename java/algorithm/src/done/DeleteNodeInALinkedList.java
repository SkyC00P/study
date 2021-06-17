package done;

import datastruct.ListNode;

public class DeleteNodeInALinkedList {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Delete Node in a Linked List.
     * Memory Usage: 38 MB, less than 7.85% of Java online submissions for Delete Node in a Linked List
     */
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
