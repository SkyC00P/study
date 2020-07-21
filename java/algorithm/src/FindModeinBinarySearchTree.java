import datastruct.TreeNode;

import java.util.*;

/**
 * 这道题让我们求二分搜索树中的众数，这里定义的二分搜索树中左根右结点之间的关系是小于等于的
 * 所谓的众数就是出现最多次的数字，可以有多个
 */
public class FindModeinBinarySearchTree {

    /**
     * Runtime: 15 ms, faster than 5.63% of Java online submissions for Find Mode in Binary Search Tree.
     * Memory Usage: 41.1 MB, less than 38.66% of Java online submissions for Find Mode in Binary Search Tree.
     */
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> counts = new HashMap<>();
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.remove(0);
            int v = node.val;
            counts.put(v, counts.getOrDefault(v, 0) + 1);
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        int max = 0;
        for (Integer k : counts.keySet()) {
            int num = counts.get(k);
            if (num > max) {
                max = num;
            }
        }
        List<Integer> _list = new ArrayList<>();
        for (Integer k : counts.keySet()) {
            if (counts.get(k) == max){
                _list.add(k);
            }
        }
        return _list.stream().mapToInt(Integer::valueOf).toArray();
    }

}
