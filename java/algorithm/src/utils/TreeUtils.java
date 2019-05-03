package utils;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class TreeUtils {
    public static TreeNode createTree(String str) {
        String[] arr = str.split(",");
        if (arr.length == 0 || arr[0].equals("null")) {
            return null;
        }
        TreeNode root = createNode(arr[0]);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 0; i < arr.length; i += 2) {
            TreeNode node = queue.poll();
            if (node != null) {
                node.left = createNode(arr, i + 1);
                node.right = createNode(arr, i + 2);
                queue.offer(node.left);
                queue.offer(node.right);
            } else break;
        }
        return root;
    }

    public static TreeNode createNode(String[] arr, int i) {
        if (i < arr.length) {
            return createNode(arr[i]);
        }
        return null;
    }

    public static TreeNode createNode(String s) {
        if (s == null || "null".equals(s.trim())) {
            return null;
        }
        return new TreeNode(Integer.parseInt(s));
    }

    public static String toString(TreeNode tree) {
        if (tree == null) return "[]";

        StringBuilder sb = new StringBuilder("[");
        LinkedList<TreeNode> queue = new LinkedList<>();
        sb.append(tree.val).append(",");
        TreeNode node = tree;
        while (node != null) {
            TreeNode left = node.left;
            TreeNode right = node.right;

            if (left == null && right == null) {
                node = queue.poll();
                continue;
            }

            if (left == null) {
                sb.append("null,");
                sb.append(right.val).append(",");
                queue.offer(right);
            } else if (right == null) {
                sb.append(left.val).append(",");
                sb.append("null,");
                queue.offer(left);
            } else {
                sb.append(left.val).append(",");
                sb.append(right.val).append(",");
                queue.offer(left);
                queue.offer(right);
            }
            node = queue.poll();
        }

        sb.deleteCharAt(sb.length() - 1);
        return sb.append("]").toString();
    }

    public static TreeNode findNode(TreeNode tree, int num) {
        if (tree == null) {
            return null;
        }
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(tree);
        TreeNode node = null;
        while (!queue.isEmpty()) {
            node = queue.poll();
            if (node.val == num) {
                break;
            }
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }

        return node;
    }
}
