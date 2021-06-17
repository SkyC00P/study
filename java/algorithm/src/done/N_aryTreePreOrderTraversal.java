package done;

import java.util.*;

public class N_aryTreePreOrderTraversal {

    static class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }

    /**
     * Runtime: 2 ms, faster than 55.79% of Java online submissions for N-ary Tree Preorder Traversal.
     * Memory Usage: 43.2 MB, less than 5.18% of Java online submissions for N-ary Tree Preorder Traversal.
     */
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        preorder(list, root);
        return list;
    }

    /**
     * Runtime: 4 ms, faster than 18.33% of Java online submissions for N-ary Tree Preorder Traversal.
     * Memory Usage: 42.9 MB, less than 5.18% of Java online submissions for N-ary Tree Preorder Traversal.
     *    1
     *  3 2 4
     * 5 6
     * s:1
     * s:4,2,3 -> 1
     * s:4,2,6,5 -> 1,3
     * s:4,2,6 -> 1,3,5
     * s:4,2 -> 1,3,5,6
     * s:4 -> 1,3,5,6,2
     * s: -> 1,3,5,6,2,4
     */
    public List<Integer> preorder_no_recursive(Node root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) {
            return list;
        }

        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            list.add(node.val);
            List<Node> children = node.children;
            if (children != null && !children.isEmpty()) {
                int len = children.size();
                for (int i = len - 1; i >= 0; i--) {
                    stack.push(children.get(i));
                }
            }
        }
        return list;
    }

    private void preorder(List<Integer> list, Node root) {
        if (root == null) {
            return;
        }
        list.add(root.val);
        for (Node node : root.children) {
            preorder(list, node);
        }
    }

}
