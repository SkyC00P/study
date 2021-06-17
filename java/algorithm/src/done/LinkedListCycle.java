package done;

import datastruct.ListNode;

import java.util.HashSet;
import java.util.Set;

/**
 * Can you solve it using O(1) (i.e. constant) memory?
 */
public class LinkedListCycle {
    /**
     * Runtime: 5 ms, faster than 18.54% of Java online submissions for Linked List Cycle.
     * Memory Usage: 39.2 MB, less than 5.15% of Java online submissions for Linked List Cycle.
     */
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        Set<ListNode> set = new HashSet<>();
        ListNode node = head;
        while (true) {
            if (set.contains(node)) {
                return true;
            }
            if (node.next == null) {
                return false;
            }
            set.add(node);
            node = node.next;
        }
    }

    public boolean hasCycle1(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
