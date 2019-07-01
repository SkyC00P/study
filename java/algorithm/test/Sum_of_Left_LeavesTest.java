import datastruct.TreeNode;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import static org.junit.jupiter.api.Assertions.*;

class Sum_of_Left_LeavesTest {

    Sum_of_Left_Leaves solution = new Sum_of_Left_Leaves();

    @Test
    void sumOfLeftLeaves() {
        TreeNode root = TreeUtils.createTree("3,9,20,null,null,15,17");
        assertEquals(24, solution.sumOfLeftLeaves(root));

        root= TreeUtils.createTree("1,2,3,4,5");
        assertEquals(4, solution.sumOfLeftLeaves(root));
    }
}