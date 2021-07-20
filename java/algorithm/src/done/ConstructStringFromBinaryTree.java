package done;

import datastruct.TreeNode;
import utils.TreeUtils;

public class ConstructStringFromBinaryTree {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Construct String from Binary Tree.
     * Memory Usage: 39.1 MB, less than 80.55% of Java online submissions for Construct String from Binary Tree.
     */
    public String tree2str(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        tree2str(root, sb);
        return sb.toString();
    }

    private void tree2str(TreeNode node, StringBuilder sb) {
        if (node == null) return;
        sb.append(node.val);
        if (node.left == null && node.right == null) return;
        if (node.left == null) {
            sb.append("()(");
            tree2str(node.right, sb);
            sb.append(")");
            return;
        }
        sb.append("(");
        tree2str(node.left, sb);
        sb.append(")");
        if (node.right != null) {
            sb.append("(");
            tree2str(node.right, sb);
            sb.append(")");
        }
    }

    public static void main(String[] args) {
        ConstructStringFromBinaryTree main = new ConstructStringFromBinaryTree();
        TreeNode node = TreeUtils.createTree("1,2,3,4");
        System.out.println(main.tree2str(node));
        node = TreeUtils.createTree("1,2,3,null,4");
        System.out.println(main.tree2str(node));
    }
}
