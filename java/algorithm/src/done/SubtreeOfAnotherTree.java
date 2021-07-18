package done;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;

public class SubtreeOfAnotherTree {

    /**
     * Runtime: 3 ms, faster than 95.17% of Java online submissions for Subtree of Another Tree.
     * Memory Usage: 39.2 MB, less than 59.08% of Java online submissions for Subtree of Another Tree.
     */
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        Queue<TreeNode> nodes = new ArrayDeque<>();
        nodes.add(root);
        while (!nodes.isEmpty()) {
            TreeNode node = nodes.poll();
            if (equalTree(node, subRoot)) {
                return true;
            }
            if (node.left != null) nodes.add(node.left);
            if (node.right != null) nodes.add(node.right);
        }
        return false;
    }

    private boolean equalTree(TreeNode node, TreeNode subRoot) {
        if (node == null && subRoot == null) return true;
        if (node == null || subRoot == null) return false;
        if (node.val != subRoot.val) return false;
        return equalTree(node.left, subRoot.left) && equalTree(node.right, subRoot.right);
    }
}
