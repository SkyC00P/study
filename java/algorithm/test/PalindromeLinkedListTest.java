import datastruct.ListNode;
import done.PalindromeLinkedList;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import static org.junit.jupiter.api.Assertions.*;

class PalindromeLinkedListTest {

    PalindromeLinkedList solution = new PalindromeLinkedList();

    @Test
    void isPalindrome() {
        ListNode node = ListUtils.createList(new int[]{1, 2}, -1);
        assertFalse(solution.isPalindrome(node));

        ListNode rightNode = ListUtils.createList(new int[]{1, 2, 2, 1}, -1);
        assertTrue(solution.isPalindrome(rightNode));
    }

    @Test
    void isPalindrome_1() {
        ListNode node = ListUtils.createList(new int[]{1, 2}, -1);
        assertFalse(solution.isPalindrome_1(node));

        ListNode rightNode = ListUtils.createList(new int[]{1, 2, 2, 1}, -1);
        assertTrue(solution.isPalindrome_1(rightNode));
    }

    @Test
    void reversalHalf() {
        printHalf(new int[]{1, 2});
        printHalf(new int[]{1, 2, 1});
        printHalf(new int[]{1, 2, 2, 1});
    }

    private void printHalf(int[] listNode) {
        System.out.println("Print start");
        ListNode node = ListUtils.createList(listNode, -1);
        ListNode rMid = solution.reversalHalf(node, listNode.length);
        ListUtils.print(node);
        ListUtils.print(rMid);
        System.out.println("Print end");
        System.out.println();
    }
}
