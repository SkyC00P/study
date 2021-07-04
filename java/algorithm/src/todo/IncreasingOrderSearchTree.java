package todo;

import java.util.Stack;

public class IncreasingOrderSearchTree {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {}

        TreeNode(int val) { this.val = val; }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public TreeNode increasingBST(TreeNode root) {
        //
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        while (node != null) {
            if (node.left == null) {
                if (node.right != null) {
                    stack.push(node.right);
                } else {
                    return root;
                }
            } else {

            }

        }
        return root;
    }
}
