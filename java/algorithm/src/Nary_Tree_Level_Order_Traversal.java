import datastruct.NTreeNode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
public class Nary_Tree_Level_Order_Traversal {

    /**
     * Runtime: 3 ms, faster than 75.58% of Java online submissions for N-ary Tree Level Order Traversal.
     * Memory Usage: 49.4 MB, less than 24.95% of Java online submissions for N-ary Tree Level Order Traversal.
     */
    public List<List<Integer>> levelOrder(NTreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) {
            return list;
        }
        Queue<NTreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int curlevelSize = 1;
        int nextLevelSize = 0;

        NTreeNode node = null;
        while (!queue.isEmpty()) {
            List<Integer> levelList = new ArrayList<>();
            while (curlevelSize-- > 0) {
                node = queue.poll();
                assert node != null;
                levelList.add(node.val);

                if (node.children != null) {
                    queue.addAll(node.children);
                    nextLevelSize += node.children.size();
                }
            }
            curlevelSize = nextLevelSize;
            nextLevelSize = 0;
            list.add(levelList);
        }

        return list;
    }
}
