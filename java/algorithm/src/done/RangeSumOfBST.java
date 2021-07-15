package done;

import datastruct.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class RangeSumOfBST {

    /**
     * Runtime: 2 ms, faster than 21.17% of Java online submissions for Range Sum of BST.
     * Memory Usage: 46.5 MB, less than 96.37% of Java online submissions for Range Sum of BST.
     */
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        List<TreeNode> list = new ArrayList<>();
        addNode(root, low, high, list);
        int sum = 0;
        for (TreeNode n : list) {
            sum += n.val;
        }
        return sum;
    }

    private void addNode(TreeNode node, int low, int high, List<TreeNode> list) {
        if (node == null) return;
        if (node.val >= low && node.val <= high) list.add(node);
        addNode(node.left, low, high, list);
        addNode(node.right, low, high, list);
    }

}
