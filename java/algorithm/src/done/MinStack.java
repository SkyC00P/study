package done;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * Your done.MinStack object will be instantiated and called as such:
 * done.MinStack obj = new done.MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 *
 * Runtime: 48 ms, faster than 80.89% of Java online submissions for Min Stack.
 * Memory Usage: 37.8 MB, less than 96.53% of Java online submissions for Min Stack.
 *
 */
public class MinStack {

    private List<Integer> list = new LinkedList<>();
    private int min = 0;
    private boolean hasMin = false;

    public MinStack() {

    }

    public void push(int x) {
        list.add(0, x);
        if (!hasMin || x < min) {
            hasMin = true;
            min = x;
        }
    }

    public void pop() {
        if (list.isEmpty()) return;
        int rm = list.remove(0);
        if (rm == min) {
            if (list.isEmpty()) {
                hasMin = false;
                return;
            }
            Iterator<Integer> iterable = list.iterator();
            min = iterable.next();
            while (iterable.hasNext()) {
                int n = iterable.next();
                if (n < min) {
                    min = n;
                }
            }
        }
    }

    public int top() {
        return list.get(0);
    }

    public int getMin() {
        return min;
    }
}
