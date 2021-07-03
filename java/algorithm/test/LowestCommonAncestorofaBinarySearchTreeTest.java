import datastruct.TreeNode;
import done.LowestCommonAncestorofaBinarySearchTree;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import static org.junit.jupiter.api.Assertions.*;

class LowestCommonAncestorofaBinarySearchTreeTest {

    LowestCommonAncestorofaBinarySearchTree solution = new LowestCommonAncestorofaBinarySearchTree();

    @Test
    void lowestCommonAncestor() {
        TreeNode tree = TreeUtils.createTree("6,2,8,0,4,7,9,null,null,3,5");
        TreeNode p = TreeUtils.findNode(tree, 2);
        TreeNode q = TreeUtils.findNode(tree, 8);
        TreeNode node = solution.lowestCommonAncestor(tree, p, q);
        assertNotNull(node);
        assertEquals(6, node.val);
        assertNotNull(node.left);
        assertEquals(2, node.left.val);
        assertNotNull(node.right);
        assertEquals(8, node.right.val);

        // 6,2,8,0,4,7,9,null,null,3,5
        tree = TreeUtils.createTree("6,2,8,0,4,7,9,null,null,3,5");
        p = TreeUtils.findNode(tree, 2);
        q = TreeUtils.findNode(tree, 4);
        node = solution.lowestCommonAncestor(tree, p, q);
        assertNotNull(node);
        assertEquals(2, node.val);
        assertNotNull(node.left);
        assertEquals(0, node.left.val);
        assertNotNull(node.right);
        assertEquals(4, node.right.val);

    }
}
