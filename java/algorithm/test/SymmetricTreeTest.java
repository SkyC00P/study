import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.*;

class SymmetricTreeTest {

    SymmetricTree solution = new SymmetricTree();

    @Test
    void isSymmetric() {
        SymmetricTree.TreeNode root = createTree("1,2,2,3,4,4,3");
        assertTrue(solution.isSymmetric(root));

        root = createTree("1,2,2,null,3,null,3");
        assertFalse(solution.isSymmetric(root));
    }

    @Test
    void test() {
        SymmetricTree.TreeNode root = createTree("1,2,2,3,4,4,3");
        assertEquals("[1,2,2,3,4,4,3]", treeToStr(root));

        root = createTree("1,2,2,null,3,null,3");
        assertEquals("[1,2,2,null,3,null,3]", treeToStr(root));
    }

    private SymmetricTree.TreeNode createTree(String str) {
        String[] arr = str.split(",");
        if (arr.length == 0 || arr[0].equals("null")) {
            return null;
        }
        SymmetricTree.TreeNode root = createNode(arr[0]);
        Queue<SymmetricTree.TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 0; i < arr.length; i += 2) {
            SymmetricTree.TreeNode node = queue.poll();
            if (node != null) {
                node.left = createNode(arr, i + 1);
                node.right = createNode(arr, i + 2);
                queue.offer(node.left);
                queue.offer(node.right);
            } else break;
        }
        return root;
    }

    private SymmetricTree.TreeNode createNode(String[] arr, int i) {
        if (i < arr.length) {
            return createNode(arr[i]);
        }
        return null;
    }

    private String treeToStr(SymmetricTree.TreeNode tree) {
        if (tree == null) return "[]";

        StringBuilder sb = new StringBuilder("[");
        LinkedList<SymmetricTree.TreeNode> queue = new LinkedList<>();
        sb.append(tree.val).append(",");
        SymmetricTree.TreeNode node = tree;
        while (node != null) {
            SymmetricTree.TreeNode left = node.left;
            SymmetricTree.TreeNode right = node.right;

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


    private SymmetricTree.TreeNode createNode(String s) {
        if (s == null || "null".equals(s.trim())) {
            return null;
        }
        return solution.new TreeNode(Integer.parseInt(s));
    }
}