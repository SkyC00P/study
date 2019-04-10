public class RemoveDuplicatesfromSortedList {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted List.
     * Memory Usage: 37.6 MB, less than 62.31% of Java online submissions for Remove Duplicates from Sorted List.
     */
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while(cur != null){
            if(cur.next == null){
                break;
            }
            if(cur.val == cur.next.val){
                cur.next = cur.next.next;
            }else{
                cur = cur.next;
            }
        }
        return head;
    }
}

