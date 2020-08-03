import java.util.Stack;

public class ConvertBinaryNumber_in_a_LinkedList_to_Integer {

    class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    /**
     * Runtime: 1 ms, faster than 29.99% of Java online submissions for Convert
     * Binary Number in a Linked List to Integer. Memory Usage: 36.7 MB, less than
     * 92.66% of Java online submissions for Convert Binary Number in a Linked List
     * to Integer.
     */
    public int getDecimalValue(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        stack.push(head);
        do {
            ListNode node = stack.peek();
            if (node.next != null) {
                stack.push(node.next);
            } else {
                break;
            }
        } while (true);

        int num = 0, index = 0;
        while (!stack.isEmpty()) {
            ListNode node = stack.pop();
            double n = node.val * Math.pow(2, index);
            num += n;
            index++;
        }
        return num;
    }
}