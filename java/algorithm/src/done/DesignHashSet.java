package done;

import java.util.ArrayList;
import java.util.List;

public class DesignHashSet {
    /**
     * Runtime: 12 ms, faster than 75.30% of Java online submissions for Design HashSet.
     * Memory Usage: 46.9 MB, less than 58.43% of Java online submissions for Design HashSet.
     */
    class MyHashSet {

        List[] list = new ArrayList[1069];

        /**
         * Initialize your data structure here.
         */
        public MyHashSet() {

        }

        public void add(int key) {
            int index = key % 1069;
            List l = this.list[index];
            if (l == null) l = new ArrayList();
            if (!l.contains(key)) {
                l.add(key);
            }
            this.list[index] = l;
        }

        public void remove(int key) {
            int index = key % 1069;
            List l = this.list[index];
            if (l == null) return;
            l.remove(Integer.valueOf(key));
        }

        /**
         * Returns true if this set contains the specified element
         */
        public boolean contains(int key) {
            int index = key % 1069;
            List l = this.list[index];
            if (l == null) return false;
            return l.contains(key);
        }
    }

}
