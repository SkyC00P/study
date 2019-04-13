import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class BinaryTreeLevelOrderTraversalI {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    /**
     * Runtime: 1 ms, faster than 88.20% of Java online submissions for Binary Tree Level Order Traversal II.
     * Memory Usage: 37.3 MB, less than 45.19% of Java online submissions for Binary Tree Level Order Traversal II
     */
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if(root != null){
            Stack<List<TreeNode>> stack = new Stack<>();

            List<TreeNode> nodeList = new ArrayList<>();
            nodeList.add(root);
            stack.push(nodeList);

            while (true){
                List<TreeNode> l = new ArrayList<>();
                for(TreeNode node : nodeList){
                    if(node.left != null){
                        l.add(node.left);
                    }

                    if(node.right != null){
                        l.add(node.right);
                    }
                }
                if(l.isEmpty()){
                    break;
                }else {
                    stack.push(l);
                    nodeList = l;
                }
            }

            while(!stack.isEmpty()){
                List<TreeNode> l = stack.pop();
                List<Integer> integers = new ArrayList<>();
                for(TreeNode node : l){
                    integers.add(node.val);
                }
                list.add(integers);
            }
        }
        return list;
    }


}
