package datastruct;

import java.util.ArrayList;
import java.util.List;

public class NTreeNode {
    public int val;
    public List<NTreeNode> children = new ArrayList<>();

    public NTreeNode() {}

    public NTreeNode(int _val, List<NTreeNode> _children) {
        val = _val;
        children = _children;
    }

    public NTreeNode(int _val) {
        val = _val;
    }
}
