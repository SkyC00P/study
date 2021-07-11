package done;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;

public class SearchInABinarySearchTree {
    /**
     * Runtime: 2 ms, faster than 100.00% of Java online submissions for Search in a Binary Search Tree.
     * Memory Usage: 39.7 MB, less than 68.14% of Java online submissions for Search in a Binary Search Tree.
     */
    public TreeNode searchBST(TreeNode root, int val) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        if (root == null) return null;
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.val == val) return node;
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return null;
    }
}
