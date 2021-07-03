import datastruct.NTreeNode;
import done.Nary_Tree_Level_Order_Traversal;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class Nary_Tree_Level_Order_TraversalTest {

    Nary_Tree_Level_Order_Traversal test = new Nary_Tree_Level_Order_Traversal();

    @Test
    void levelOrder() {
        String strNode = "1-3,2,4|3-5,6|2|4";
        NTreeNode root = TreeUtils.createNTree(strNode);
        assertEquals(strNode, TreeUtils.toString(root));
        List<List<Integer>> list = test.levelOrder(root);

    }
}
