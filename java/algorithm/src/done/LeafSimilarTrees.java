package done;

import datastruct.TreeNode;
import utils.TreeUtils;

import java.util.*;

public class LeafSimilarTrees {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Leaf-Similar Trees.
     * Memory Usage: 36.9 MB, less than 49.93% of Java online submissions for Leaf-Similar Trees.
     */
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<TreeNode> t1 = new ArrayList<>();
        List<TreeNode> t2 = new ArrayList<>();

        getLeaf(root1, t1);
        getLeaf(root2, t2);

        if (t1.size() != t2.size()) return false;
        for (int i = 0; i < t1.size(); i++) {
            TreeNode n1 = t1.get(i);
            TreeNode n2 = t2.get(i);

            if (n1 == null || n2 == null) return false;
            if (n1.val != n2.val) return false;
        }
        return true;
    }

    private void getLeaf(TreeNode r, List<TreeNode> t) {
        if (r == null) return;
        getLeaf(r.left, t);
        getLeaf(r.right, t);
        if (r.left == null && r.right == null) t.add(r);
    }

    public static void main(String[] args) {
        LeafSimilarTrees main = new LeafSimilarTrees();
        TreeNode t1 = TreeUtils.createTree("3,5,1,6,2,9,8,null,null,7,4");
        TreeNode t2 = TreeUtils.createTree("3,5,1,6,7,4,2,null,null,null,null,null,null,9,8");
        System.out.println(main.leafSimilar(t1, t2));

    }
}
