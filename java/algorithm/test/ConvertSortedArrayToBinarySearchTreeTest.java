import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConvertSortedArrayToBinarySearchTreeTest {

    ConvertSortedArrayToBinarySearchTree solution = new ConvertSortedArrayToBinarySearchTree();

    @Test
    void sortedArrayToBST() {
        int[] arr = new int[]{-10, -3, 0, 5, 9};
        ConvertSortedArrayToBinarySearchTree.TreeNode node = solution.sortedArrayToBST(arr);
        ConvertSortedArrayToBinarySearchTree.TreeNode realNode = createTree();
        assertTrue(isTheSame(node, realNode));
    }

    private boolean isTheSame(ConvertSortedArrayToBinarySearchTree.TreeNode node, ConvertSortedArrayToBinarySearchTree.TreeNode realNode) {
        return false;
    }

    /**
     *      0
     *   /    |
     * -3   9
     * /   /
     * -10  5
     *
     * @return
     */
    private ConvertSortedArrayToBinarySearchTree.TreeNode createTree() {
        return null;
    }
}