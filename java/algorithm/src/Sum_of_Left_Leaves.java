import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;

public class Sum_of_Left_Leaves {
    /**
     * Runtime: 1 ms, faster than 16.73% of Java online submissions for Sum of Left Leaves.
     * Memory Usage: 36 MB, less than 100.00% of Java online submissions for Sum of Left Leaves.
     */
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        int sum = 0;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                if (isLeaf(node.left)) {
                    sum += node.left.val;
                } else {
                    queue.add(node.left);
                }
            }

            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return sum;
    }

    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
