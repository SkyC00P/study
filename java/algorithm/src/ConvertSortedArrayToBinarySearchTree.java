import java.util.Stack;

/**
 * http://www.cnblogs.com/skywang12345/p/3577479.html
 * 了解平衡二叉树的原理，这道题就可以做。
 * 主要理解 LL,RR,LR,RL 四个旋转
 * 这道题也可以用二分法来做，因为数组已经是有序的了。
 */
public class ConvertSortedArrayToBinarySearchTree {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    /**
     * 这里是假设数组无序的情况下的通用做法
     * Runtime: 9 ms, faster than 24.79% of Java online submissions for Convert Sorted Array to Binary Search Tree.
     * Memory Usage: 38.8 MB, less than 5.12% of Java online submissions for Convert Sorted Array to Binary Search Tree.
     */
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        TreeNode root = insertNode(null, nums[0]);
        for (int i = 1; i < nums.length; i++) {
            root = insertNode(root, nums[i]);
        }
        return root;
    }

    /**
     * 向二叉树插入值并返回根结点
     */
    private TreeNode insertNode(TreeNode root, int x) {
        if (root == null) {
            return new TreeNode(x);
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode insertNode = root;
        while (insertNode != null) {
            if (x < insertNode.val) {
                if (insertNode.left == null) {
                    insertNode.left = new TreeNode(x);
                    break;
                } else {
                    stack.push(insertNode);
                    insertNode = insertNode.left;
                }
            } else if (x > insertNode.val) {
                if (insertNode.right == null) {
                    insertNode.right = new TreeNode(x);
                    break;
                } else {
                    stack.push(insertNode);
                    insertNode = insertNode.right;
                }
            } else {
                return root;
            }
        }

        // 找到最低受到影响的结点
        TreeNode node = null;
        while (!stack.isEmpty()) {
            node = stack.pop();
            int balance_factor = Math.abs(height(node.left) - height(node.right));
            if (balance_factor > 1) {
                break;
            } else {
                node = null;
            }
        }

        if (node != null) {
            TreeNode befNode = stack.isEmpty() ? null : stack.pop();
            TreeNode newNode = null;
            if (x < node.val) {
                if (x < node.left.val) {
                    newNode = LL(node);
                } else {
                    newNode = LR(node);
                }
            } else {
                if (x < node.right.val) {
                    newNode = RL(node);
                } else {
                    newNode = RR(node);
                }
            }
            if (befNode == null) {
                return newNode;
            } else if (befNode.left == node) {
                befNode.left = newNode;
            } else if (befNode.right == node) {
                befNode.right = newNode;
            }
        }
        return root;
    }

    private TreeNode RR(TreeNode node) {
        TreeNode root = node.right;
        node.right = root.left;
        root.left = node;
        return root;
    }

    private TreeNode RL(TreeNode node) {
        node.right = LL(node.right);
        return RR(node);
    }

    private TreeNode LR(TreeNode node) {
        node.left = RR(node.left);
        return LL(node);
    }

    private TreeNode LL(TreeNode node) {
        TreeNode root = node.left;
        node.left = root.right;
        root.right = node;
        return root;
    }

    private int height(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return 1;
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Convert Sorted Array to Binary Search Tree.
     * Memory Usage: 37.6 MB, less than 73.18% of Java online submissions for Convert Sorted Array to Binary Search Tree
     */
    public TreeNode sortedArrayToBST_1(int[] nums) {
        return helper(nums, 0, nums.length-1);
    }

    private TreeNode helper(int[] nums, int l, int r){
        if (l>r) return null;
        if (l==r) return new TreeNode(nums[l]);
        int mid = (l+r)/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = helper(nums, l, mid-1);
        root.right = helper(nums, mid+1, r);
        return root;
    }

}
