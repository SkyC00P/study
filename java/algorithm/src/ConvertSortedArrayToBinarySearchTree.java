/**
 * http://www.cnblogs.com/skywang12345/p/3577479.html
 * 了解平衡二叉树的原理，这道题就可以做。
 * 主要理解 LL,RR,LR,RL 四个旋转
 */
public class ConvertSortedArrayToBinarySearchTree {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        TreeNode root = insertNode(null, nums[0]);
        for (int i = 1; i < nums.length; i++) {
            root = insertNode(root, nums[i]);
        }
        return root;
    }

    /**
     * 向二叉树插入值并返回根结点
     */
    private TreeNode insertNode(TreeNode root, int x) {
        if (root == null) {
            return new TreeNode(x);
        }
        return root;
    }

    private void RR(TreeNode node) {

    }

    private void RL(TreeNode node) {

    }

    private void LR(TreeNode node) {

    }

    private void LL(TreeNode node) {

    }

    private int height(TreeNode node) {
        return 0;
    }
}
