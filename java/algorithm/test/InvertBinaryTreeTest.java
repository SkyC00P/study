import datastruct.TreeNode;
import done.InvertBinaryTree;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import static org.junit.jupiter.api.Assertions.*;

class InvertBinaryTreeTest {

    InvertBinaryTree solution = new InvertBinaryTree();

    @Test
    void invertTree() {
        TreeNode root = TreeUtils.createTree("4,2,7,1,3,6,9");
        assertNotNull(root);
        root = solution.invertTree(root);
        TreeNode real = TreeUtils.createTree("4,7,2,9,6,3,1");
        assertNotNull(real);
        assertEquals(TreeUtils.toString(real), TreeUtils.toString(root));
    }
}
