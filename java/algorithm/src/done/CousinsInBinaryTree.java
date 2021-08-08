package done;

import datastruct.TreeNode;
import utils.TreeUtils;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class CousinsInBinaryTree {

    class nNode {
        TreeNode parent;
        TreeNode node;
        int height;
    }

    /**
     * Runtime: 1 ms, faster than 27.48% of Java online submissions for Cousins in Binary Tree.
     * Memory Usage: 36.8 MB, less than 39.27% of Java online submissions for Cousins in Binary Tree.
     */
    public boolean isCousins(TreeNode root, int x, int y) {
        int height = 1;
        int count = 1;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        List<nNode> list = new ArrayList<>();
        check(x, y, root, 0, null, list);
        while (list.size() != 2) {
            int _count = 0;
            while (count != 0) {
                TreeNode node = queue.poll();
                count--;
                if (node.left != null) {
                    TreeNode left = node.left;
                    check(x, y, left, height, node, list);
                    _count++;
                    queue.add(left);
                }
                if (node.right != null) {
                    TreeNode right = node.right;
                    check(x, y, right, height, node, list);
                    _count++;
                    queue.add(right);
                }
            }
            height++;
            count = _count;
        }

        nNode n1 = list.get(0);
        nNode n2 = list.get(1);
        return n1 != null && n2 != null && n1.height == n2.height && n1.parent != n2.parent;
    }

    private void check(int x, int y, TreeNode node, int height, TreeNode parent, List<nNode> list) {
        if (node.val == x || node.val == y) {
            nNode nx = new nNode();
            nx.height = height + 1;
            nx.parent = parent;
            nx.node = node;
            list.add(nx);
        }
    }

    public static void main(String[] args) {
        CousinsInBinaryTree main = new CousinsInBinaryTree();
//        TreeNode node = TreeUtils.createTree("1,2,3,4");
//        System.out.println(main.isCousins(node, 4, 3));
        // [1,null,2,3,null,null,4,null,5]
//        TreeNode node = TreeUtils.createTree("1,null,2,3,null,null,4,null,5");
//        System.out.println(main.isCousins(node, 1, 3));
        TreeNode node = TreeUtils.createTree("1,2,3,null,null,null,4,5");
        System.out.println(main.isCousins(node, 1, 2));
    }
}
