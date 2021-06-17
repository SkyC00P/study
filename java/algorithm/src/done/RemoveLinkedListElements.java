package done;

import datastruct.ListNode;

public class RemoveLinkedListElements {
    /**
     * Runtime: 1 ms, faster than 99.62% of Java online submissions for Remove Linked List Elements.
     * Memory Usage: 40.6 MB, less than 86.68% of Java online submissions for Remove Linked List Elements
     */
    public ListNode removeElements(ListNode head, int val) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode node = head;
        while (cur != null) {
            if (cur.val == val) {
                if (cur == node) {
                    node = node.next;
                    cur = node;
                } else {
                    pre.next = cur.next;
                    cur = cur.next;
                }
            }else {
                pre = cur;
                cur = cur.next;
            }
        }
        return node;
    }
}
