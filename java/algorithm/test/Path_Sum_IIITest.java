import datastruct.TreeNode;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import static org.junit.jupiter.api.Assertions.*;

class Path_Sum_IIITest {

    Path_Sum_III test = new Path_Sum_III();

    @Test
    void pathSum() {
        TreeNode root = TreeUtils.createTree("10,5,-3,3,2,null,11,3,-2,null,1");
        assertEquals(3, test.pathSum(root, 8));
    }
}