package utils;

import datastruct.TailInvoke;
import datastruct.TailRecursion;

public class MathUtils {

    /**
     * 阶乘 - 容易爆栈
     *
     * @param n
     * @return
     */
    public static int factorial(int n) {
        return n <= 1 ? n : n * factorial(n - 1);
    }

    /**
     * 尾递归 - java 编译器默认没有对其进行优化，所以还是会爆栈
     */
    public static int factorial_tail_recursion(int n) {
        return tail_recursion(1, n);
    }

    private static int tail_recursion(int num, int n) {
        return n == 1 ? num : tail_recursion(num * n, n - 1);
    }

    /**
     * lambda的懒加载(惰性求值)机制来延迟递归的调用，从而实现栈帧的复用
     */
    public static int factorial_lambda(int n) {
        return factorialTailRecursion(1, n).invoke();
    }

    public static TailRecursion<Integer> factorialTailRecursion(final int factorial, final int number) {
        if (number == 1)
            return TailInvoke.done(factorial);
        else
            return TailInvoke.call(() -> factorialTailRecursion(factorial * number, number - 1));
    }

    public static void main(String[] args) {
        for (int i = 1; i < 10; i++) {
            System.out.println(i + " - " + factorial(i));
        }
        for (int i = 1; i < 10; i++) {
            System.out.println(i + " - " + factorial_tail_recursion(i));
        }
        for (int i = 1; i < 1000; i++) {
            System.out.println(i + " - " + factorial_lambda(i));
        }
        System.out.println(factorial_lambda(1808548329));
    }
}
