/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * <p>
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * height' should probably not be passed as parameter 'x' less... (Ctrl+F1)
 * Inspection info: Reports assignments and function calls where the name of the variable to which a value is assigned or the function parameter does not seem to match the name of the value assigned to it. For example:
 *   int x = 0;
 *   int y = x;
 * or
 *   int x = 0, y = 0;
 *   Rectangle rc = new Rectangle(y, x, 20, 20);
 * The configuration pane allows to specify the names which should not be used together: the error is reported if the parameter name or assignment target name contains words from one group and the name of the assigned or passed variable contains words from a different group.
 */
public class AddTwoNumbers {
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int param) {
            val = param;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode node = new ListNode(0);
        ListNode curNode = node;
        ListNode l1_n = l1;
        ListNode l2_n = l2;
        int height = 0;

        while (true) {
            int l1_val = l1_n == null ? 0 : l1_n.val;
            int l2_val = l2_n == null ? 0 : l2_n.val;

            int sum = l1_val + l2_val + height;
            if (sum >= 10) {
                curNode.val = sum % 10;
                height = sum / 10;
            } else {
                curNode.val = sum;
                height = 0;
            }
            l1_n = l1_n == null ? null : l1_n.next;
            l2_n = l2_n == null ? null : l2_n.next;

            if (l1_n == null && l2_n == null) {
                if(height != 0){
                    curNode.next = new ListNode(height);
                }
                break;
            }
            ListNode newNode = new ListNode(0);
            curNode.next = newNode;
            curNode = newNode;
        }
        return node;
    }

    public static void main(String[] args) {
        AddTwoNumbers solution = new AddTwoNumbers();
        ListNode l1 = solution.create(new int[]{2, 4, 3});
        ListNode l2 = solution.create(new int[]{5, 6, 4});
        ListNode result = solution.addTwoNumbers(l1, l2);
        solution.print(result);

        l1 = solution.create(new int[]{5});
        l2 = solution.create(new int[]{5});
        result = solution.addTwoNumbers(l1, l2);
        solution.print(result);
    }

    private void print(ListNode result) {
        if (result != null) {
            ListNode cur = result;
            while (cur != null) {
                System.out.print(cur.val + "->");
                cur = cur.next;
            }
            System.out.print("null");
        }
        System.out.println();
    }

    private ListNode create(int[] nums) {
        ListNode node = new ListNode(0);
        ListNode cur = node;
        for (int i = 0; i < nums.length - 1; i++) {
            cur.val = nums[i];
            ListNode next = new ListNode(0);
            cur.next = next;
            cur = next;
        }
        cur.val = nums[nums.length - 1];
        cur.next = null;
        return node;
    }


}
