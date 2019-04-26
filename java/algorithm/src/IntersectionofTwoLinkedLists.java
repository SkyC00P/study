import datastruct.ListNode;

import java.util.HashSet;
import java.util.Set;

public class IntersectionofTwoLinkedLists {
    /**
     * Runtime: 8 ms, faster than 17.22% of Java online submissions for Intersection of Two Linked Lists.
     * Memory Usage: 39.4 MB, less than 7.45% of Java online submissions for Intersection of Two Linked Lists
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> set = new HashSet<>();
        ListNode node = headA;
        while (node != null) {
            set.add(node);
            node = node.next;
        }
        node = headB;
        while (node != null) {
            if (set.contains(node)) return node;
            node = node.next;
        }
        return null;
    }
}
