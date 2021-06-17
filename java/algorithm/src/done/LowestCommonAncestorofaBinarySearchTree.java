package done;

import datastruct.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;

public class LowestCommonAncestorofaBinarySearchTree {

    /**
     * Runtime: 4 ms, faster than 100.00% of Java online submissions for Lowest Common Ancestor of a Binary Search Tree.
     * Memory Usage: 35.4 MB, less than 10.11% of Java online submissions for Lowest Common Ancestor of a Binary Search Tree.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (root == null) return null;
        Queue<TreeNode> pQueue = new ArrayDeque<>();
        Queue<TreeNode> qQueue = new ArrayDeque<>();

        initQueue(pQueue, root, p);
        initQueue(qQueue, root, q);

        return findLastCommonNode(pQueue, qQueue);
    }

    private TreeNode findLastCommonNode(Queue<TreeNode> q1, Queue<TreeNode> q2) {
        TreeNode q1_node = null;
        TreeNode q2_node = null;
        TreeNode node = null;
        while(!q1.isEmpty() && !q2.isEmpty()){
            q1_node = q1.poll();
            q2_node = q2.poll();

            if(q1_node != q2_node){
                break;
            }else{
                node = q1_node;
            }
        }
        return node;
    }

    private void initQueue(Queue<TreeNode> queue, TreeNode root, TreeNode p) {

        TreeNode node = root;
        while (node != null) {
            queue.add(node);
            if (node == p) {
                break;
            }
            if (p.val > node.val) {
                node = node.right;
            }else{
                node = node.left;
            }
        }
    }

}
