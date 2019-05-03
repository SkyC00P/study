import java.util.Stack;

public class ImplementQueueUsingStacks {

    /**
     * Runtime: 42 ms, faster than 84.30% of Java online submissions for Implement Queue using Stacks.
     * Memory Usage: 33 MB, less than 100.00% of Java online submissions for Implement Queue using Stacks.
     */
    public static class MyQueue {

        private Stack<Integer> stack;
        private int head = 0;

        /**
         * Initialize your data structure here.
         */
        public MyQueue() {
            stack = new Stack<>();
        }

        /**
         * Push element x to the back of queue.
         */
        public void push(int x) {
            if(empty()){
                head = x;
            }
            stack.push(x);
        }

        /**
         * Removes the element from in front of queue and returns that element.
         */
        public int pop() {
            Stack<Integer> container = new Stack<>();
            while(!stack.isEmpty()){
                container.push(stack.pop());
            }
            int element = container.pop();
            if(!container.isEmpty()){
                head = container.pop();
                stack.push(head);
            }
            while(!container.isEmpty()){
                stack.push(container.pop());
            }
            return element;
        }

        /**
         * Get the front element.
         */
        public int peek() {
            return head;
        }

        /**
         * Returns whether the queue is empty.
         */
        public boolean empty() {
            return stack.empty();
        }
    }
}
