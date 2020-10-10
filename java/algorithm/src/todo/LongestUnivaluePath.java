package todo;
import java.util.LinkedList;
import java.util.List;

public class LongestUnivaluePath {

    public class TreeNode {
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

    public int longestUnivaluePath(TreeNode root) {
        if(root == null) return 0;
        int path = 0;
        List<TreeNode> nodes = new LinkedList<>();
        nodes.add(root);
        while (!nodes.isEmpty()) {
            TreeNode node = nodes.remove(0);
            int p = countUnivaluePath(node.left, node.val, 0) + countUnivaluePath(node.right, node.val, 0);
            if (p > path) {
                path = p;
            }
            if (node.left != null) {
                nodes.add(node.left);
            }
            if (node.right != null) {
                nodes.add(node.right);
            }
        }
        return path;
    }

    private int countUnivaluePath(TreeNode node, int v, int n) {
        if(node == null){
            return n;
        }
        if(node.val == v){
            n++;
        }
        int left = countUnivaluePath(node.left, v, n);
        int right = countUnivaluePath(node.right, v, n);
        return Math.max(left, right);
    }
}
