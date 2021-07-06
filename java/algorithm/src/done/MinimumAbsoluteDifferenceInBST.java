package done;
public class MinimumAbsoluteDifferenceInBST {
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    int res = Integer.MAX_VALUE;
    int prev = -1;

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Minimum Absolute Difference in BST.
     * Memory Usage: 38.8 MB, less than 62.30% of Java online submissions for Minimum Absolute Difference in BST.
     */
    public int getMinimumDifference(TreeNode root) {
        traverse(root);
        return res;
    }

    public void traverse(TreeNode root) {
        if (root != null) {
            traverse(root.left);
            if (prev == -1) {
                prev = root.val;
            } else {
                res = Math.min(res, Math.abs(prev - root.val));
                prev = root.val;
            }
            traverse(root.right);
        }
    }
}
