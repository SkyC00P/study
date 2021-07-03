package done;

public class MiddleOfTheLinkedList {

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {}

        ListNode(int val) { this.val = val; }

        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Middle of the Linked List.
     * Memory Usage: 36.3 MB, less than 56.73% of Java online submissions for Middle of the Linked List.
     */
    public ListNode middleNode(ListNode head) {
        if (head.next == null) return head;
        int size = 0;
        ListNode node = head;
        while (node != null) {
            size++;
            node = node.next;
        }
        int i = (size / 2) + 1;
        node = null;
        do {
            if (node == null) {
                node = head;
            } else {
                node = node.next;
            }
            i--;
        } while (i != 0);
        return node;
    }
}
