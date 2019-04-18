import datastruct.TreeNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumDepthofBinaryTreeTest {

    MinimumDepthofBinaryTree solution = new MinimumDepthofBinaryTree();

    @Test
    void minDepth() {
        TreeNode node = new TreeNode(3);
        node.left = new TreeNode(9);
        node.right = new TreeNode(20);
        node.right.left = new TreeNode(15);
        node.right.right = new TreeNode(7);

        assertEquals(2, solution.minDepth(node));

        node = new TreeNode(1);
        node.left = new TreeNode(2);
        assertEquals(2, solution.minDepth(node));
    }
}