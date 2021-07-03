import datastruct.TreeNode;
import done.ConvertSortedArrayToBinarySearchTree;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;

import static org.junit.jupiter.api.Assertions.*;

class ConvertSortedArrayToBinarySearchTreeTest {

    ConvertSortedArrayToBinarySearchTree solution = new ConvertSortedArrayToBinarySearchTree();

    @Test
    void sortedArrayToBST() {
        int[] arr = new int[]{-10, -3, 0, 5, 9};
        TreeNode node = solution.sortedArrayToBST(arr);
        assertTrue(checkNode(node));
    }

    private boolean checkNode(TreeNode node) {
        if (node == null) return true;
        if (node.left == null && node.right == null) return true;

        if (node.left != null) {
            if (node.left.val > node.val) return false;
        }
        if (node.right != null) {
            if (node.right.val < node.val) return false;
        }
        if (Math.abs(height(node.left) - height(node.right)) > 1) {
            return false;
        }
        return checkNode(node.left) && checkNode(node.right);
    }

    @Test
    void test() {

    }

    private int height(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return 1;
        return Math.max(height(node.left), height(node.right)) + 1;
    }
}
