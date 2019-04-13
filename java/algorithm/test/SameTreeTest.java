import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.*;

class SameTreeTest {

    SameTree solution = new SameTree();

    @Test
    void isSameTree() {
        SameTree.TreeNode t1 = createTree("1,2,3");
        SameTree.TreeNode t2 = createTree("1,2,3");

        assertTrue(solution.isSameTree(t1, t1));

        assertNotSame(t1, t2);
        assertTrue(solution.isSameTree(t1, t2));

        SameTree.TreeNode t3 = createTree("1,2,1");
        SameTree.TreeNode t4 = createTree("1,1,2");
        assertNotSame(t3, t4);
        assertFalse(solution.isSameTree(t3, t4));

        SameTree.TreeNode t5 = createTree("1,2");
        SameTree.TreeNode t6 = createTree("1,null,2");
        assertFalse(solution.isSameTree(t5, t6));
    }

    private SameTree.TreeNode createTree(String str) {
        String[] arr = str.split(",");
        if (arr.length == 0 || arr[0].equals("null")) {
            return null;
        }
        SameTree.TreeNode root = createNode(arr[0]);
        Queue<SameTree.TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 0; i < arr.length; i += 2) {
            SameTree.TreeNode node = queue.poll();
            if (node != null) {
                node.left = createNode(arr, i + 1);
                node.right = createNode(arr, i + 2);
                queue.offer(node.left);
                queue.offer(node.right);
            } else break;
        }
        return root;
    }

    private SameTree.TreeNode createNode(String[] arr, int i) {
        if (i < arr.length) {
            return createNode(arr[i]);
        }
        return null;
    }

    private SameTree.TreeNode createNode(String s) {
        if (s == null || "null".equals(s.trim())) {
            return null;
        }
        return solution.new TreeNode(Integer.parseInt(s));
    }

    private String treeToStr(SameTree.TreeNode tree) {
        if (tree == null) return "[]";

        StringBuilder sb = new StringBuilder("[");
        LinkedList<SameTree.TreeNode> queue = new LinkedList<>();
        sb.append(tree.val).append(",");
        SameTree.TreeNode node = tree;
        while (node != null) {
            SameTree.TreeNode left = node.left;
            SameTree.TreeNode right = node.right;

            if (left == null && right == null) {
                node = queue.poll();
                continue;
            }

            if (left == null) {
                sb.append("null,");
                sb.append(right.val).append(",");
                queue.offer(right);
            } else if (right == null) {
                sb.append(left.val).append(",");
                sb.append("null,");
                queue.offer(left);
            } else {
                sb.append(left.val).append(",");
                sb.append(right.val).append(",");
                queue.offer(left);
                queue.offer(right);
            }
            node = queue.poll();
        }

        sb.deleteCharAt(sb.length() - 1);
        return sb.append("]").toString();
    }

    @Test
    void test() {
        SameTree.TreeNode root = createTree("1,2,2,3,4,4,3");
        assertEquals("[1,2,2,3,4,4,3]", treeToStr(root));

        root = createTree("1,2,2,null,3,null,3");
        assertEquals("[1,2,2,null,3,null,3]", treeToStr(root));
    }
}