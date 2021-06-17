package done;

import datastruct.ListNode;

import java.util.Stack;

/**
 * Could you do it in O(n) time and O(1) space?
 */
public class PalindromeLinkedList {

    /**
     * Runtime: 3 ms, faster than 21.09% of Java online submissions for Palindrome Linked List.
     * Memory Usage: 41.3 MB, less than 95.80% of Java online submissions for Palindrome Linked List.
     */
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        Stack<ListNode> stack = new Stack<>();
        ListNode node = head;
        while (node != null) {
            stack.push(node);
            node = node.next;
        }

        node = head;
        while (!stack.isEmpty()) {
            ListNode pNode = stack.pop();
            if (node.val != pNode.val) {
                return false;
            }
            node = node.next;
        }
        return true;
    }

    /**
     * Runtime: 1 ms, faster than 95.15% of Java online submissions for Palindrome Linked List.
     * Memory Usage: 41.2 MB, less than 95.80% of Java online submissions for Palindrome Linked List.
     */
    public boolean isPalindrome_1(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        int size = 0;
        ListNode tail = null;
        ListNode cur = head;
        while (cur != null) {
            tail = cur;
            cur = cur.next;
            size++;
        }

        reversalHalf(head, size);
        ListNode lNode = head;
        ListNode rNode = tail;

        while (lNode != null && rNode != null) {
            if (lNode.val != rNode.val) {
                return false;
            }
            lNode = lNode.next;
            rNode = rNode.next;
        }
        return true;
    }

    public ListNode reversalHalf(ListNode head, int size) {
        boolean isEvent = (size & 1) == 0;
        int mid = isEvent ? size / 2 : (size + 1) / 2;

        ListNode cur = head;
        for (int i = 1; i < mid; i++) {
            cur = cur.next;
        }

        ListNode lmid = cur;
        ListNode rmid = isEvent ? cur.next : cur;

        ListNode pre = null;
        cur = rmid;
        ListNode next = null;

        while (cur != null){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        lmid.next = null;
        return pre;
    }
}
