import datastruct.TreeNode;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import static org.junit.jupiter.api.Assertions.*;

class MinimumDepthofBinaryTreeTest {

    MinimumDepthofBinaryTree solution = new MinimumDepthofBinaryTree();

    @Test
    void minDepth() {
        TreeNode node;
        node = TreeUtils.createTree("3,9,20,null,null,15,7");
        assertEquals(2, solution.minDepth(node));

        node = TreeUtils.createTree("1,2");
        assertEquals(2, solution.minDepth(node));

        node = TreeUtils.createTree("1,2,3,4,null,null,5");
        assertEquals(3, solution.minDepth(node));

        node = TreeUtils.createTree("1,null,2");
        assertEquals(2, solution.minDepth(node));
    }
}