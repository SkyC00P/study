/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * <p>
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * }
 */
public class MergeTwoSortedLists {
    /**
     * Runtime: 1 ms, faster than 96.44% of Java online submissions for Merge Two Sorted Lists.
     * Memory Usage: 37 MB, less than 97.95% of Java online submissions for Merge Two Sorted Lists.
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode l1_n = l1;
        ListNode l2_n = l2;
        ListNode node = getMinNode(l1_n, l2_n);
        ListNode cur = node;
        while (cur != null) {
            l1_n = cur == l1_n ? cur.next : l1_n;
            l2_n = cur == l2_n ? cur.next : l2_n;
            cur.next = getMinNode(l1_n, l2_n);
            cur = cur.next;
        }
        return node;
    }

    private ListNode getMinNode(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        return l1.val <= l2.val ? l1 : l2;
    }

    public static void main(String[] args) {
        MergeTwoSortedLists solution = new MergeTwoSortedLists();
        ListNode l1 = createNode(new int[]{1, 2, 4});
        ListNode l2 = createNode(new int[]{1, 3, 4});
        System.out.println(String.format("%s + %s", NodeToString(l1), NodeToString(l2)));
        ListNode node = solution.mergeTwoLists(l1, l2);
        System.out.println(NodeToString(node).equals("1->1->2->3->4->4->null"));
    }

    private static String NodeToString(ListNode l) {
        ListNode node = l;
        StringBuilder sb = new StringBuilder();
        while (node != null) {
            sb.append(node.val).append("->");
            node = node.next;
        }
        sb.append("null");
        return sb.toString();
    }

    private static ListNode createNode(int[] arr) {
        ListNode node = new ListNode(arr[0]);
        ListNode cur = node;
        for (int i = 1; i < arr.length; i++) {
            cur.next = new ListNode(arr[i]);
            cur = cur.next;
        }
        return node;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
