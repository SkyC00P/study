package done;

import datastruct.TreeNode;

import java.util.*;

public class BinaryTreePaths {
    /**
     * Runtime: 3 ms, faster than 65.35% of Java online submissions for Binary Tree Paths.
     * Memory Usage: 37.5 MB, less than 62.66% of Java online submissions for Binary Tree Paths.
     */
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<>();
        if (root == null) return list;

        Set<TreeNode> visitSet = new HashSet<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            visitSet.add(node);
            if (isChild(node)) {
                list.add(converToStr(stack, node));
                continue;
            }

            stack.push(node);
            TreeNode lNode = node.left;
            if (lNode != null && !visitSet.contains(lNode)) {
                stack.push(lNode);
                continue;
            }
            TreeNode rNode = node.right;
            if (rNode != null && !visitSet.contains(rNode)) {
                stack.push(rNode);
                continue;
            }

            stack.pop();
        }

        return list;
    }

    private String converToStr(Stack<TreeNode> stack, TreeNode node) {
        List<TreeNode> list = new ArrayList<>(stack);
        StringBuilder sb = new StringBuilder();
        for (TreeNode n : list) {
            sb.append(n.val).append("->");
        }
        return sb.append(node.val).toString();
    }

    private boolean isChild(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
