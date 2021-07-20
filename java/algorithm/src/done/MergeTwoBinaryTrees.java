package done;

import datastruct.TreeNode;

public class MergeTwoBinaryTrees {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Merge Two Binary Trees.
     * Memory Usage: 39.4 MB, less than 45.36% of Java online submissions for Merge Two Binary Trees.
     */
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return null;
        if (root1 == null || root2 == null) return root1 == null ? root2 : root1;
        TreeNode root = new TreeNode(root1.val + root2.val);
        mergeTreesLeft(root, root1.left, root2.left);
        mergeTreesRight(root, root1.right, root2.right);
        return root;
    }

    private void mergeTreesLeft(TreeNode root, TreeNode l_node, TreeNode r_node) {
        if (l_node == null && r_node == null) {
            root.left = null;
            return;
        }
        if (l_node == null || r_node == null) {
            root.left = l_node == null ? r_node : l_node;
            return;
        }
        root.left = new TreeNode(l_node.val + r_node.val);
        mergeTreesLeft(root.left, l_node.left, r_node.left);
        mergeTreesRight(root.left, l_node.right, r_node.right);
    }

    private void mergeTreesRight(TreeNode root, TreeNode l_node, TreeNode r_node) {
        if (l_node == null && r_node == null) {
            root.right = null;
            return;
        }
        if (l_node == null || r_node == null) {
            root.right = l_node == null ? r_node : l_node;
            return;
        }
        root.right = new TreeNode(l_node.val + r_node.val);
        mergeTreesLeft(root.right, l_node.left, r_node.left);
        mergeTreesRight(root.right, l_node.right, r_node.right);
    }
}
