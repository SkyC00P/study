import datastruct.TreeNode;
import done.BinaryTreePaths;
import org.junit.jupiter.api.Test;
import utils.TreeUtils;

import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreePathsTest {

    BinaryTreePaths solution = new BinaryTreePaths();

    @Test
    void binaryTreePaths() {
        TreeNode tree = TreeUtils.createTree("1,2,3,null,5");
        List<String> list = solution.binaryTreePaths(tree);
        assertNotNull(list);
        assertEquals(2, list.size());
        Set<String> set = new HashSet<>(list);
        assertTrue(set.contains("1->2->5"));
        assertTrue(set.contains("1->3"));
    }

    @Test
    void test(){
        Stack<String> stack = new Stack<>();
        stack.push("1");
        stack.push("2");
        List<String> list = new ArrayList<>(stack);
        System.out.println(list);
    }
}
