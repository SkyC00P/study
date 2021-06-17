package done;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;

public class InvertBinaryTree {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Invert Binary Tree.
     * Memory Usage: 35.6 MB, less than 70.62% of Java online submissions for Invert Binary Tree.
     */
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        TreeNode node = null;
        while (!queue.isEmpty()) {
            node = queue.poll();
            TreeNode leftNode = node.left;
            TreeNode rightNode = node.right;

            node.right = leftNode;
            node.left = rightNode;

            if (leftNode != null) {
                queue.add(leftNode);
            }

            if (rightNode != null) {
                queue.add(rightNode);
            }
        }
        return root;
    }
}
