package done;

import datastruct.TreeNode;
import utils.TreeUtils;

import java.util.ArrayDeque;
import java.util.Queue;

public class DiameterOfBinaryTree {
    /**
     * Runtime: 15 ms, faster than 5.32% of Java online submissions for Diameter of Binary Tree.
     * Memory Usage: 39.1 MB, less than 39.76% of Java online submissions for Diameter of Binary Tree.
     */
    public int diameterOfBinaryTree(TreeNode root) {
        int max = 0;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            int l_height = findHeight(node.left);
            int r_height = findHeight(node.right);
            int len = l_height + r_height;
            if (len > max) {
                max = len;
            }
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return max;
    }

    private int findHeight(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) {
            return 1;
        }
        int l_h = findHeight(node.left);
        int r_h = findHeight(node.right);
        return Math.max(l_h, r_h) + 1;
    }

    public static void main(String[] args) {
        DiameterOfBinaryTree main = new DiameterOfBinaryTree();
        TreeNode node = null;
//        node = TreeUtils.createTree("1,2,3,4,5");
//        System.out.println(main.findHeight(node));
//        System.out.println(main.diameterOfBinaryTree(node));

//        node = TreeUtils.createTree("4,1,null,2,null,3");
//        System.out.println(TreeUtils.toString(node));
//        System.out.println(main.findHeight(node));
//        System.out.println(main.diameterOfBinaryTree(node));

        // [4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
        node = TreeUtils.createTree("4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2");
        System.out.println(TreeUtils.toString(node));
        System.out.println(main.findHeight(node));
        System.out.println(main.diameterOfBinaryTree(node));
    }

}
