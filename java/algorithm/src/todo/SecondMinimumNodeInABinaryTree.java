package todo;

import datastruct.TreeNode;
import utils.TreeUtils;

public class SecondMinimumNodeInABinaryTree {

    public int findSecondMinimumValue(TreeNode root) {
        int n1 = findMin(root.left, root.val, root.val);
        int n2 = findMin(root.right, root.val, root.val);
        if (n1 != -1 && n2 != -1) return Math.min(n1, n2);
        if (n1 == -1 && n2 == -1) return -1;
        return n1 == -1 ? n2 : n1;
    }

    private int findMin(TreeNode node, int val, int root) {
        if (node == null) return -1;

        int n1 = findMin(node.left, node.val, root);
        int n2 = findMin(node.right, node.val, root);

        if (n1 == -1 && n2 == -1) return -1;
        if (n1 != -1 && n2 != -1) return Math.min(n1, n2);
        return n1 == -1 ? n2 : n1;
    }

    public static void main(String[] args) {
        datastruct.TreeNode tree = TreeUtils.createTree("2,2,5,null,null,5,7");
        SecondMinimumNodeInABinaryTree test = new SecondMinimumNodeInABinaryTree();
        tree = TreeUtils.createTree("1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1");
        System.out.println(test.findSecondMinimumValue(tree) == 2);
    }
}
