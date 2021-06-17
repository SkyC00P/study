package done;

import datastruct.TreeNode;

public class SameTree {

    /**
     * 解这个问题不用几秒
     * 倒是怎么将规定好的字符串转化为树，数组变为树，然后再层序遍历转为字符串花了我不少时间
     * 即建立单元测试的时间用了一个晚上，但是解这道题，只用了几秒并且一次过。
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Same Tree.
     * Memory Usage: 35.6 MB, less than 96.28% of Java online submissions for Same Tree
     */
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == q) return true;
        if(p == null || q == null) return false;
        if(p.val != q.val) return false;
        if(!isSameTree(p.left, q.left)) return false;
        return isSameTree(p.right, q.right);
    }
}


