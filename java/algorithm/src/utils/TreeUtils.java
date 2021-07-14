package utils;

import datastruct.NTreeNode;
import datastruct.TreeNode;

import java.util.*;

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
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            } else break;
        }
        return root;
    }

    private static TreeNode createNode(String[] arr, int i) {
        if (i < arr.length) {
            return createNode(arr[i]);
        }
        return null;
    }

    private static TreeNode createNode(String s) {
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
                sb.append("null,null,");
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

    /**
     * 1|1:3,2,4|3:5,6;5:7,7
     */
    public static NTreeNode createNTree(String s) {
        String[] lev = s.split("\\|");
        NTreeNode root = new NTreeNode(Integer.parseInt(lev[0]));
        Map<String, List<NTreeNode>> map = new HashMap<>();
        map.put(0 + "-" + root.val, root.children);

        for (int i = 1; i < lev.length; i++) {
            String[] bros = lev[i].split(";");
            // 1:3,2,4
            for (String bro : bros) {
                String[] a1 = bro.split(":", 2);
                String p1 = i - 1 + "-" + a1[0];
                String children = a1[1];

                List<NTreeNode> nTreeNodes = map.get(p1);
                for (String n : children.split(",")) {
                    NTreeNode node = new NTreeNode(Integer.parseInt(n));
                    map.put(i + "-" + node.val, node.children);
                    nTreeNodes.add(node);
                }

            }
        }
        return root;
    }

    // 1|1:3,2,4|3:5,6;4:7,7
    public static String toString(NTreeNode tree) {
        if (tree == null) return "null";
        StringBuilder sb = new StringBuilder(tree.val);
        Map<Integer, List<NTreeNode>> lastLev = new HashMap<>();
        lastLev.put(tree.val, tree.children);
        sb.append(tree.val).append("|");
        do {
            Map<Integer, List<NTreeNode>> curLev = new HashMap<>();
            if (lastLev.isEmpty()) break;

            for (Integer val : lastLev.keySet()) {
                List<NTreeNode> nTreeNodes = lastLev.get(val);
                if (nTreeNodes.isEmpty()) continue;
                sb.append(val).append(":");
                nTreeNodes.forEach(l -> {
                    sb.append(l.val).append(",");
                    curLev.put(l.val, l.children);
                });
                sb.deleteCharAt(sb.length() - 1);
                sb.append(";");
            }
            sb.deleteCharAt(sb.length() - 1);
            sb.append("|");
            lastLev = curLev;
        } while (true);
        return sb.deleteCharAt(sb.length() - 1).toString();
    }

    public static void main(String[] args) {
        System.out.println(toString(TreeUtils.createNTree("1|1:3,2,4|3:5,6;4:7,7")));
    }
}
