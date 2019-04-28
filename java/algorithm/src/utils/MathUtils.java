package utils;

public class MathUtils {

    public static int factorial(int n) {
        return n <= 1 ? n : n * factorial(n - 1);
    }

    public static void main(String[] args) {
        for (int i = 1; i < 20; i++) {
            System.out.println(i + " - " + factorial(i));
        }
    }
}
