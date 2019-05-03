import datastruct.TreeNode;

public class BalancedBinaryTree {

    public boolean isBalanced(TreeNode node) {
        if (node == null) return true;
        if (node.left == null && node.right == null) return true;

        if (Math.abs(height(node.left) - height(node.right)) > 1) {
            return false;
        }
        return isBalanced(node.left) && isBalanced(node.right);
    }

    private int height(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return 1;
        return Math.max(height(node.left), height(node.right)) + 1;
    }
}
