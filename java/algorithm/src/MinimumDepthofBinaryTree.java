import datastruct.TreeNode;

public class MinimumDepthofBinaryTree {

    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        if (root.left == null) {
            return minDepth(root.right, 1);
        } else if (root.right == null) {
            return minDepth(root.left, 1);
        }
        return minDepth(root, 0);
    }

    private int minDepth(TreeNode root, int i) {
        if (root == null) return i;
        i += 1;
        if (root.left == null && root.right == null) {
            return i;
        }
        int l = minDepth(root.left, i);
        int r = minDepth(root.right, i);
        return l >= r ? r : l;
    }
}
