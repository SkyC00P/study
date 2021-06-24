package done;

import java.util.ArrayList;
import java.util.List;

public class BinaryTreeInorderTraversal {

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

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Inorder Traversal.
     * Memory Usage: 37.7 MB, less than 17.85% of Java online submissions for Binary Tree Inorder Traversal.
     */
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        loop(root, list);
        return list;
    }

    private void loop(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        loop(root.left, list);
        list.add(root.val);
        loop(root.right, list);
    }
}
