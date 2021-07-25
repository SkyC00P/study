package todo;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class MinimumDistanceBetweenBST_Nodes {

    /**
     * Runtime: 2 ms, faster than 9.68% of Java online submissions for Minimum Distance Between BST Nodes.
     * Memory Usage: 36.4 MB, less than 76.32% of Java online submissions for Minimum Distance Between BST Nodes.
     */
    public int minDiffInBST(TreeNode root) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        if (root == null) return 0;
        queue.add(root);
        List<Integer> list = new ArrayList<>();

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            list.add(node.val);
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }

        list.sort(Integer::compareTo);
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < list.size(); i++) {
            int n1 = list.get(i);
            int n2 = list.get(i - 1);
            int n = Math.abs(n1 - n2);
            if (n < min) {
                min = n;
            }
        }
        return min;
    }
}
