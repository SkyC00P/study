package done;

import datastruct.TreeNode;
import utils.TreeUtils;

import java.util.ArrayDeque;
import java.util.Queue;

public class BinaryTreeTilt {

    /**
     * Runtime: 20 ms, faster than 5.56% of Java online submissions for Binary Tree Tilt.
     * Memory Usage: 38.6 MB, less than 93.27% of Java online submissions for Binary Tree Tilt.
     */
    public int findTilt(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        int sum = 0;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            sum += findTiltInOneNode(node);
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return sum;
    }

    private int findTiltInOneNode(TreeNode node) {
        if (node == null) return 0;
        int l_val = sumOfTree(node.left);
        int r_val = sumOfTree(node.right);
        return Math.abs(l_val - r_val);
    }

    private int sumOfTree(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return node.val;
        return sumOfTree(node.left) + sumOfTree(node.right) + node.val;
    }

    public static void main(String[] args) {
        BinaryTreeTilt main = new BinaryTreeTilt();
        TreeNode tree = TreeUtils.createTree("1,2,3");
        System.out.println(main.findTilt(tree));

        tree = TreeUtils.createTree("4,2,9,3,5,null,7");
        System.out.println(main.findTilt(tree));
    }

}
