import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BalancedBinaryTreeTest {

    BalancedBinaryTree solution = new BalancedBinaryTree();

    @Test
    void isBalanced() {
        BalancedBinaryTree.TreeNode root = solution.new TreeNode(3);
        root.left = solution.new TreeNode(9);
        root.right = solution.new TreeNode(20);
        root.right.left = solution.new TreeNode(15);
        root.right.right = solution.new TreeNode(7);
        assertTrue(solution.isBalanced(root));

        root = solution.new TreeNode(1);
        root.left = solution.new TreeNode(2);
        root.right = solution.new TreeNode(2);
        root.left.left = solution.new TreeNode(3);
        root.left.right = solution.new TreeNode(3);
        root.left.left.left = solution.new TreeNode(4);
        root.left.left.right = solution.new TreeNode(4);
        assertFalse(solution.isBalanced(root));
    }
}