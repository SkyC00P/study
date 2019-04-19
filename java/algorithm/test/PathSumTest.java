import datastruct.TreeNode;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import static org.junit.jupiter.api.Assertions.*;

class PathSumTest {

    PathSum solution = new PathSum();

    @Test
    void hasPathSum() {
        TreeNode root = TreeUtils.createTree("5,4,8,11,null,13,4,7,2,null,null,null,1");
        assertTrue(solution.hasPathSum(root, 22));
    }
}