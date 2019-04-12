import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SameTreeTest {

    SameTree solution = new SameTree();

    @Test
    void isSameTree() {
        SameTree.TreeNode t1 = createTree(new int[]{1, 2, 3});
        SameTree.TreeNode t2 = createTree(new int[]{1, 2, 3});
        SameTree.TreeNode t3 = createTree(new int[]{1, 2, 1});
        SameTree.TreeNode t4 = createTree(new int[]{1, 1, 2});

        assertTrue(solution.isSameTree(t1, t1));

        assertTrue(t1 != t2);
        assertTrue(solution.isSameTree(t1, t2));

        assertTrue(t3 != t4);
        assertFalse(solution.isSameTree(t3, t4));
    }

    private SameTree.TreeNode createTree(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        SameTree.TreeNode head = solution.new TreeNode(arr[0]);
        SameTree.TreeNode node = head;

        for (int i = 1; i < arr.length; i++) {
            node.left = solution.new TreeNode(arr[0]);
            node.right = solution.new TreeNode(arr[0]);
        }
        return head;
    }

    /**
     * 按程序遍历
     */
    private String treeToStr(SameTree.TreeNode tree) {
        StringBuilder sb = new StringBuilder();

        return sb.toString();
    }
}