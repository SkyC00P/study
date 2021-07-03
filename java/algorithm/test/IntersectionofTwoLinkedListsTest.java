import datastruct.ListNode;
import done.IntersectionofTwoLinkedLists;
import org.junit.jupiter.api.Test;
import utils.ListUtils;

import static org.junit.jupiter.api.Assertions.*;

class IntersectionofTwoLinkedListsTest {

    IntersectionofTwoLinkedLists solution = new IntersectionofTwoLinkedLists();

    /**
     * 8
     * [4,1,8,4,5]
     * [5,0,1,8,4,5]
     * 2
     * 3
     */
    @Test
    void getIntersectionNode() {
        ListNode ha = ListUtils.createList(new int[]{4, 1}, -1);
        ListNode hb = ListUtils.createList(new int[]{5, 0, 1}, -1);
        ListNode nodes = ListUtils.createList(new int[]{8, 4, 5}, -1);
        ha = ListUtils.combine(ha, nodes);
        hb = ListUtils.combine(hb, nodes);

        ListUtils.print(ha);
        ListUtils.print(hb);

        ListNode node = solution.getIntersectionNode(ha, hb);
        assertNotNull(node);
        assertEquals(8, node.val);
        assertNotNull(node.next);
        assertEquals(4, node.next.val);
    }
}
