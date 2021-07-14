package done;

import datastruct.NTreeNode;
import utils.TreeUtils;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MaximumDepthOfN_aryTree {

    /**
     * Runtime: 1 ms, faster than 43.68% of Java online submissions for Maximum Depth of N-ary Tree.
     * Memory Usage: 38.9 MB, less than 84.14% of Java online submissions for Maximum Depth of N-ary Tree.
     */
    public int maxDepth(NTreeNode root) {
        if (root == null) return 0;
        if (root.children == null) return 1;

        int cur = 1;
        Map<Integer, List<NTreeNode>> map = new HashMap<>();
        map.put(1, root.children);

        while (true) {
            List<NTreeNode> rm = map.remove(cur);
            if (rm == null || rm.isEmpty()) break;
            List<NTreeNode> list = new ArrayList<>();

            cur += 1;
            for (NTreeNode node : rm) {
                if (node.children != null) {
                    list.addAll(node.children);
                }
            }
            map.put(cur, list);
        }

        return cur;
    }

    public static void main(String[] args) {
        NTreeNode node = TreeUtils.createNTree("1|1:3,2,4|3:5,6");

        MaximumDepthOfN_aryTree main = new MaximumDepthOfN_aryTree();
        System.out.println(TreeUtils.toString(node));
        System.out.println(main.maxDepth(node));
    }
}
