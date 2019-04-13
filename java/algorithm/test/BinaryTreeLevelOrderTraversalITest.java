import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeLevelOrderTraversalITest {

    BinaryTreeLevelOrderTraversalI solution = new BinaryTreeLevelOrderTraversalI();

    /**
     * 3
     * / \
     * 9  20
     * /  \
     * 15   7
     * <p>
     * [
     * [15,7],
     * [9,20],
     * [3]
     * ]
     */
    @Test
    void levelOrderBottom() {
        BinaryTreeLevelOrderTraversalI.TreeNode root = createTree("3,9,20,null,null,15,7");
        List<List<Integer>> lists = solution.levelOrderBottom(root);
        List<List<Integer>> expect_list = new ArrayList<>();

        List<Integer> l1 = new ArrayList<>();
        l1.add(15);
        l1.add(7);
        expect_list.add(l1);

        List<Integer> l2 = new ArrayList<>();
        l2.add(9);
        l2.add(20);
        expect_list.add(l2);

        List<Integer> l3 = new ArrayList<>();
        l3.add(3);
        expect_list.add(l3);

        assertIterableEquals(expect_list, lists);
    }

    private BinaryTreeLevelOrderTraversalI.TreeNode createTree(String str) {
        String[] arr = str.split(",");
        if (arr.length == 0 || arr[0].equals("null")) {
            return null;
        }
        BinaryTreeLevelOrderTraversalI.TreeNode root = createNode(arr[0]);
        Queue<BinaryTreeLevelOrderTraversalI.TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 0; i < arr.length; i += 2) {
            BinaryTreeLevelOrderTraversalI.TreeNode node = queue.poll();
            if (node != null) {
                node.left = createNode(arr, i + 1);
                node.right = createNode(arr, i + 2);
                queue.offer(node.left);
                queue.offer(node.right);
            } else break;
        }
        return root;
    }

    private BinaryTreeLevelOrderTraversalI.TreeNode createNode(String[] arr, int i) {
        if (i < arr.length) {
            return createNode(arr[i]);
        }
        return null;
    }

    private BinaryTreeLevelOrderTraversalI.TreeNode createNode(String s) {
        if (s == null || "null".equals(s.trim())) {
            return null;
        }
        return solution.new TreeNode(Integer.parseInt(s));
    }

    private String treeToStr(BinaryTreeLevelOrderTraversalI.TreeNode tree) {
        if (tree == null) return "[]";

        StringBuilder sb = new StringBuilder("[");
        LinkedList<BinaryTreeLevelOrderTraversalI.TreeNode> queue = new LinkedList<>();
        sb.append(tree.val).append(",");
        BinaryTreeLevelOrderTraversalI.TreeNode node = tree;
        while (node != null) {
            BinaryTreeLevelOrderTraversalI.TreeNode left = node.left;
            BinaryTreeLevelOrderTraversalI.TreeNode right = node.right;

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
        BinaryTreeLevelOrderTraversalI.TreeNode root = createTree("1,2,2,3,4,4,3");
        assertEquals("[1,2,2,3,4,4,3]", treeToStr(root));

        root = createTree("1,2,2,null,3,null,3");
        assertEquals("[1,2,2,null,3,null,3]", treeToStr(root));
    }
}