import datastruct.TreeNode;

import java.util.*;

public class Path_Sum_III {
    /**
     * Runtime: 114 ms, faster than 5.14% of Java online submissions for Path Sum III.
     * Memory Usage: 38.5 MB, less than 89.57% of Java online submissions for Path Sum III
     */
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }

        int pathSum = 0;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        TreeNode node = null;
        while (!queue.isEmpty()) {
            node = queue.poll();
            pathSum += findPath(node, sum);
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return pathSum;
    }

    public int findPath(TreeNode root, int sum) {
        // 遍历树的所有路径
        Set<TreeNode> visitSet = new HashSet<>();
        int pathSize = 0;
        int n = 0;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        TreeNode node = null;
        while (!stack.isEmpty()) {
            node = stack.peek();
            if (visitSet.contains(node)) {
                n -= stack.pop().val;
                continue;
            }
            visitSet.add(node);
            n += node.val;
            if (n == sum) {
                pathSize++;
            }

            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }

            if (node.left == null && node.right == null) {
                n -= stack.pop().val;
            }
        }

        return pathSize;
    }
}
