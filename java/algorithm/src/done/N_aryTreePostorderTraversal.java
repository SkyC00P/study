package done;

import datastruct.NTreeNode;

import java.util.ArrayList;
import java.util.List;

public class N_aryTreePostorderTraversal {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for N-ary Tree Postorder Traversal.
     * Memory Usage: 40.1 MB, less than 26.21% of Java online submissions for N-ary Tree Postorder Traversal.
     */
    public List<Integer> postorder(NTreeNode root) {
        List<Integer> list = new ArrayList<>();
        postorder(root, list);
        return list;
    }

    private void postorder(NTreeNode node, List<Integer> list) {
        if (node == null) return;
        if (node.children != null) {
            List<NTreeNode> children = node.children;
            for (NTreeNode n : children) {
                postorder(n, list);
            }
        }
        list.add(node.val);
    }
}
