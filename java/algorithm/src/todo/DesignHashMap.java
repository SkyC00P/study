package todo;

import utils.ArrayUtils;

import java.util.*;

public class DesignHashMap {
    static class MyHashMap {

        class Node {
            private int key, value, hash;
            private Node left, right, bro;

            public Node(int hash, int key, int value) {
                this.key = key;
                this.hash = hash;
                this.value = value;
            }
        }

        private int sentry = 10000;
        private Node node;

        /**
         * Initialize your data structure here.
         */
        public MyHashMap() {
        }

        /**
         * value will always be non-negative.
         */
        public void put(int key, int value) {
            Node _node = searchNode(key);
            if (_node != null) {
                _node.value = value;
                return;
            }
            if (node == null) {
                node = new Node(key % sentry, key, value);
                return;
            }
            // 根据hash和key找到插入的位置, todo : 这里插入应该做处理使得树左右平衡，避免退化为链表
            _node = new Node(key % sentry, key, value);
            Node n = node;
            insertNode(n, _node);
        }

        private Node searchNode(int key) {
            if (node == null) return null;
            int hash = key % sentry;
            Queue<Node> queue = new ArrayDeque<>();
            queue.add(node);
            while (!queue.isEmpty()) {
                Node qNode = queue.poll();
                if (qNode.hash < hash) {
                    if (qNode.right != null) {
                        queue.add(qNode.right);
                    }
                } else if (qNode.hash > hash) {
                    if (qNode.left != null) {
                        queue.add(qNode.left);
                    }
                } else {
                    if (qNode.key == key) return qNode;
                    if (qNode.bro != null) {
                        queue.add(qNode.bro);
                    }
                }
            }
            return null;
        }

        /**
         * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
         */
        public int get(int key) {
            Node node = searchNode(key);
            return node == null ? -1 : node.value;
        }

        /**
         * Removes the mapping of the specified value key if this map contains a mapping for the key
         */
        public void remove(int key) {
            if (node == null) return;
            int hash = key % sentry;
            Node c_node = node;
            Node b_node = null;
            while (c_node != null) {
                if (c_node.hash == hash) {
                    rmNode(b_node, c_node, key);
                    break;
                } else if (c_node.hash < hash) {
                    b_node = c_node;
                    c_node = c_node.right;
                } else {
                    b_node = c_node;
                    c_node = c_node.left;
                }
            }
        }

        private void rmNode(Node b_node, Node c_node, int key) {
            // 删除的可能是在兄弟结点
            if (c_node.key != key) {
                Node c_bro = c_node.bro;
                Node b_bro = c_node;
                while (c_bro != null) {
                    if (c_bro.key == key) {
                        b_bro.bro = c_bro.bro;
                        c_bro.bro = null;
                        return;
                    }
                    b_bro = c_bro;
                    c_bro = c_bro.bro;
                }
            }

            // 删除的是根结点
            if (b_node == null) {
                // 能不能被兄弟结点替代
                if (c_node.bro != null) {
                    c_node.bro.left = c_node.left;
                    c_node.bro.right = c_node.right;
                    node = c_node.bro;
                    return;
                }
                node = c_node.left == null ? c_node.right : c_node.left;
                return;
            }

            // 删除的是叶结点
            if (c_node.left == null && c_node.right == null) {
                if (c_node.hash > b_node.hash) {
                    b_node.right = null;
                } else {
                    b_node.left = null;
                }
                return;
            }

            // 删除的是中间结点
            if (c_node.bro != null) {
                // 用兄弟结点替换
                c_node.bro.left = c_node.left;
                c_node.bro.right = c_node.right;
                if (c_node.hash > b_node.hash) {
                    b_node.right = c_node.bro;
                } else {
                    b_node.left = c_node.bro;
                }
            }

            // 删除的是父节点的右节点
            if (c_node.hash > b_node.hash) {
                if (c_node.left == null) {
                    b_node.right = c_node.right;
                    c_node.right = null;
                } else {
                    b_node.right = c_node.left;
                    if (c_node.right != null) {
                        Node n = b_node.right;
                        Node i = c_node.right;
                        insertNode(n, i);
                    }
                    c_node.left = null;
                    c_node.right = null;
                    c_node.bro = null;
                }
            } else {
                if (c_node.right == null) {
                    b_node.left = c_node.left;
                    c_node.left = null;
                } else {
                    b_node.left = c_node.right;
                    if (c_node.left != null) {
                        Node n = b_node.left;
                        Node i = c_node.left;
                        insertNode(n, i);
                    }
                    c_node.left = null;
                    c_node.right = null;
                    c_node.bro = null;
                }
            }
        }

        @Override
        public String toString() {
            if (node == null) return "";
            Set<String> nums = new HashSet<>();
            Queue<Node> queue = new ArrayDeque<>();
            queue.add(node);
            while (!queue.isEmpty()) {
                Node n = queue.poll();
                nums.add(n.key + "=" + n.value);
                Node bro = n.bro;
                while (bro != null) {
                    nums.add(bro.key + "=" + bro.value);
                    bro = bro.bro;
                }
                if (n.left != null) queue.add(n.left);
                if (n.right != null) queue.add(n.right);
            }
            return nums.toString();
        }

        private void insertNode(Node n, Node _node) {
            while (true) {
                if (n.hash == _node.hash) {
                    if (n.bro != null) {
                        _node.bro = n.bro;
                    }
                    n.bro = _node;
                    break;
                }

                if (n.hash < _node.hash) {
                    if (n.right == null) {
                        n.right = _node;
                        break;
                    } else {
                        n = n.right;
                        continue;
                    }
                }

                if (n.left == null) {
                    n.left = _node;
                    break;
                } else {
                    n = n.left;
                }
            }
        }
    }

    /*
["MyHashMap","remove","put","remove","remove","get","remove","put","get","remove","put","put","put","put","put","put","put","put","put","put","put","remove","put","put","get","put","get","put","put","get","put","remove","remove","put","put","get","remove","put","put","put","get","put","put","remove","put","remove","remove","remove","put","remove","get","put","put","put","put","remove","put","get","put","put","get","put","remove","get","get","remove","put","put","put","put","put","put","get","get","remove","put","put","put","put","get","remove","put","put","put","put","put","put","put","put","put","put","remove","remove","get","remove","put","put","remove","get","put","put"]
[[],[27],[65,65],[19],[0],[18],[3],[42,0],[19],[42],[17,90],[31,76],[48,71],[5,50],[7,68],[73,74],[85,18],[74,95],[84,82],[59,29],[71,71],[42],[51,40],[33,76],[17],[89,95],[95],[30,31],[37,99],[51],[95,35],[65],[81],[61,46],[50,33],[59],[5],[75,89],[80,17],[35,94],[80],[19,68],[13,17],[70],[28,35],[99],[37],[13],[90,83],[41],[50],[29,98],[54,72],[6,8],[51,88],[13],[8,22],[85],[31,22],[60,9],[96],[6,35],[54],[15],[28],[51],[80,69],[58,92],[13,12],[91,56],[83,52],[8,48],[62],[54],[25],[36,4],[67,68],[83,36],[47,58],[82],[36],[30,85],[33,87],[42,18],[68,83],[50,53],[32,78],[48,90],[97,95],[13,8],[15,7],[5],[42],[20],[65],[57,9],[2,41],[6],[33],[16,44],[95,30]]

     */
    public static void main(String[] args) {
        MyHashMap myHashMap = new MyHashMap();
        myHashMap.put(1, 1); // The map is now [[1,1]]
        myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
        // return 1, The map is now [[1,1], [2,2]]
        System.out.println(myHashMap.get(1) == 1);
        // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
        System.out.println(myHashMap.get(3) == -1);
        myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
        // return 1, The map is now [[1,1], [2,1]]
        System.out.println(myHashMap.get(2) == 1);
        myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
        // return -1 (i.e., not found), The map is now [[1,1]]
        System.out.println(myHashMap.get(2) == -1);

        String[] ops = new String[]{
                "remove", "put", "remove", "remove", "get", "remove", "put", "get", "remove", "put", "put", "put", "put", "put", "put", "put", "put", "put", "put", "put", "remove", "put", "put", "get", "put", "get", "put", "put", "get", "put", "remove", "remove", "put", "put", "get", "remove", "put", "put", "put", "get", "put", "put", "remove", "put", "remove", "remove", "remove", "put", "remove", "get", "put", "put", "put", "put", "remove", "put", "get", "put", "put", "get", "put", "remove", "get", "get", "remove", "put", "put", "put", "put", "put", "put", "get", "get", "remove", "put", "put", "put", "put", "get", "remove", "put", "put", "put", "put", "put", "put", "put", "put", "put", "put", "remove", "remove", "get", "remove", "put", "put", "remove", "get", "put", "put"
        };

        int[][] ds = ArrayUtils.toArray("[[27],[65,65],[19],[0],[18],[3],[42,0],[19],[42],[17,90],[31,76],[48,71],[5,50],[7,68],[73,74],[85,18],[74,95],[84,82],[59,29],[71,71],[42],[51,40],[33,76],[17],[89,95],[95],[30,31],[37,99],[51],[95,35],[65],[81],[61,46],[50,33],[59],[5],[75,89],[80,17],[35,94],[80],[19,68],[13,17],[70],[28,35],[99],[37],[13],[90,83],[41],[50],[29,98],[54,72],[6,8],[51,88],[13],[8,22],[85],[31,22],[60,9],[96],[6,35],[54],[15],[28],[51],[80,69],[58,92],[13,12],[91,56],[83,52],[8,48],[62],[54],[25],[36,4],[67,68],[83,36],[47,58],[82],[36],[30,85],[33,87],[42,18],[68,83],[50,53],[32,78],[48,90],[97,95],[13,8],[15,7],[5],[42],[20],[65],[57,9],[2,41],[6],[33],[16,44],[95,30]]");
        MyHashMap map = new MyHashMap();
        for (int i = 0; i < ds.length; i++) {
            String op = ops[i];
            int[] arr = ds[i];
            switch (op) {
                case "remove":
                    System.out.print("Remove：");
                    for (int n : arr) {
                        System.out.print(n + " ");
                        map.remove(n);
                    }
                    System.out.println("当前map为:" + map);
                    break;
                case "put":
                    System.out.print(String.format("Put：%d -> %d", arr[0], arr[1]));
                    map.put(arr[0], arr[1]);
                    System.out.println("当前map为:" + map);
                    break;
                case "get":
                    System.out.println(String.format("Get Num is : %d -> %d", arr[0], map.get(arr[0])));
                    break;
            }
        }
    }
}
