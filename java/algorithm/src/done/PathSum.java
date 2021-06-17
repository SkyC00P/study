package done;

import datastruct.TreeNode;

public class PathSum {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Path Sum.
     * Memory Usage: 38.9 MB, less than 10.69% of Java online submissions for Path Sum.
     */
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        return hasPathSum(root, 0, sum);
    }

    private boolean hasPathSum(TreeNode root, int i, int sum) {
        if (isLeaf(root)) return i + root.val == sum;
        if (root.left != null && hasPathSum(root.left, i + root.val, sum)) return true;
        return root.right != null && hasPathSum(root.right, i + root.val, sum);
    }

    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }

}
