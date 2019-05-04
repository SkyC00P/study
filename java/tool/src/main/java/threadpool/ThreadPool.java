package threadpool;

import java.security.AccessController;
import java.util.Stack;
import java.util.concurrent.*;

public final class ThreadPool {

    private static final int COUNT_MASK = (1 << 29) - 1;
    public static void main(String[] args) {
        //00100000000000000000000000000000
        //00011111111111111111111111111111
        int num =  3 << 29;
        Stack<Integer> stack = new Stack<Integer>();
        for (int i = 0; i < 32; i++) {
            stack.push(num & 1);
            num = num >> 1;
        }
        while(!stack.isEmpty()){
            System.out.print(stack.pop());
        }
        System.out.println();
    }


}
