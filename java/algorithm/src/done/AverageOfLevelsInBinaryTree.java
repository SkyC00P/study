package done;

import datastruct.TreeNode;
import utils.TreeUtils;

import java.util.*;

public class AverageOfLevelsInBinaryTree {
    /**
     * Runtime: 2 ms, faster than 82.50% of Java online submissions for Average of Levels in Binary Tree.
     * Memory Usage: 41.3 MB, less than 40.47% of Java online submissions for Average of Levels in Binary Tree.
     */
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> list = new ArrayList<>();
        if (root == null) return list;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int child_num = queue.size();

        while (!queue.isEmpty()) {
            double count = child_num;
            double sum = 0;
            int next_num = 0;
            while (child_num != 0) {
                TreeNode node = queue.poll();
                sum += node.val;
                child_num--;
                if (node.left != null) {
                    queue.add(node.left);
                    next_num++;
                }
                if (node.right != null) {
                    queue.add(node.right);
                    next_num++;
                }
            }
            list.add(sum / count);
            child_num = next_num;
        }

        return list;
    }

    public static void main(String[] args) {
        AverageOfLevelsInBinaryTree main = new AverageOfLevelsInBinaryTree();
        TreeNode node = TreeUtils.createTree("3,9,20,null,null,15,7");
        System.out.println(main.averageOfLevels(node));
    }
}
