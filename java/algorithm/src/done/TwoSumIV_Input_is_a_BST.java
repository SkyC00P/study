package done;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

public class TwoSumIV_Input_is_a_BST {

    /**
     * Runtime: 8 ms, faster than 13.60% of Java online submissions for Two Sum IV - Input is a BST.
     * Memory Usage: 48.5 MB, less than 13.45% of Java online submissions for Two Sum IV - Input is a BST.
     */
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet<>();
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            int n = k - node.val;

            if (set.contains(n)) return true;
            set.add(node.val);

            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return false;
    }
}
