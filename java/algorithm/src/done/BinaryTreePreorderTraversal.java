package done;

import java.util.ArrayList;
import java.util.List;

public class BinaryTreePreorderTraversal {
    class TreeNode {
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

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Preorder Traversal.
     * Memory Usage: 37.1 MB, less than 70.13% of Java online submissions for Binary Tree Preorder Traversal.
     */
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        loop(root, list);
        return list;
    }

    private void loop(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        list.add(root.val);
        loop(root.left, list);
        loop(root.right, list);
    }
}
