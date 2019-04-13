public class MaximumDepthofBinaryTree {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

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
        return 1 + (ld >= rd ? ld : rd);
    }

}
