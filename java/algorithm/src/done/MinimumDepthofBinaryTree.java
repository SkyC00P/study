package done;

import datastruct.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class MinimumDepthofBinaryTree {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Minimum Depth of Binary Tree.
     * Memory Usage: 40.4 MB, less than 5.07% of Java online submissions for Minimum Depth of Binary Tree
     */
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(root);
        int minDepth = 1;
        while (true) {
            while (!q1.isEmpty()) {
                TreeNode node = q1.poll();
                if (node.left == null && node.right == null) {
                    return minDepth;
                } else {
                    if (node.left != null) q2.add(node.left);
                    if (node.right != null) q2.add(node.right);
                }
            }
            minDepth++;
            while (!q2.isEmpty()) {
                TreeNode node = q2.poll();
                if (node.left == null && node.right == null) {
                    return minDepth;
                } else {
                    if (node.left != null) q1.add(node.left);
                    if (node.right != null) q1.add(node.right);
                }
            }
            minDepth++;
        }

    }


}
