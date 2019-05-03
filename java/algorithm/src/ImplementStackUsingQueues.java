import java.util.ArrayDeque;
import java.util.Queue;

public class ImplementStackUsingQueues {
    /**
     * Runtime: 44 ms, faster than 87.52% of Java online submissions for Implement Stack using Queues.
     * Memory Usage: 35.4 MB, less than 98.23% of Java online submissions for Implement Stack using Queues.
     */
    public static class MyStack {

        private Queue<Integer> queue = new ArrayDeque<>();
        private int top = 0;

        /**
         * Initialize your data structure here.
         */
        public MyStack() {

        }

        /**
         * Push element x onto stack.
         */
        public void push(int x) {
            if (queue.add(x)) {
                top++;
            }
        }

        /**
         * Removes the element on top of the stack and returns that element.
         */
        public int pop() {
            int count = --top;
            while (count != 0) {
                int x = queue.remove();
                queue.add(x);
                count--;
            }
            return queue.remove();
        }

        /**
         * Get the top element.
         */
        public int top() {
            int count = top;
            int x = 0;
            while (count != 0) {
                x = queue.remove();
                queue.add(x);
                count--;
            }

            return x;
        }

        /**
         * Returns whether the stack is empty.
         */
        public boolean empty() {
            return queue.isEmpty();
        }
    }
}
