package done;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;

public class UnivaluedBinaryTree {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Univalued Binary Tree.
     * Memory Usage: 36.7 MB, less than 41.55% of Java online submissions for Univalued Binary Tree.
     */
    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return false;
        int val = root.val;
        Queue<TreeNode> queue = new ArrayDeque<>();
        if (root.left != null) queue.add(root.left);
        if (root.right != null) queue.add(root.right);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.val != val) return false;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return true;
    }
}
