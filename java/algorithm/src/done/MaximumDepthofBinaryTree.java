package done;

import datastruct.TreeNode;

public class MaximumDepthofBinaryTree {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Maximum Depth of Binary Tree.
     * Memory Usage: 39.9 MB, less than 6.34% of Java online submissions for Maximum Depth of Binary Tree
     */
    public int maxDepth(TreeNode root) {
        return maxDepth(0, root);
    }

    private int maxDepth(int i, TreeNode node) {
        if (node == null) return i;
        int ld = maxDepth(i, node.left);
        int rd = maxDepth(i, node.right);
        return 1 + (Math.max(ld, rd));
    }

}
