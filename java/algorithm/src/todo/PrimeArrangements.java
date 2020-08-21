package todo;

import java.util.HashSet;
import java.util.Set;

public class PrimeArrangements {

    Set<Integer> prime_num = new HashSet<>();
    {
        prime_num.add(2);
        prime_num.add(3);
        prime_num.add(5);
        prime_num.add(7);
        prime_num.add(11);
        prime_num.add(13);
        prime_num.add(17);
        prime_num.add(19);
        prime_num.add(23);
        prime_num.add(29);
        prime_num.add(31);
        prime_num.add(37);
        prime_num.add(41);
        prime_num.add(43);
        prime_num.add(47);
        prime_num.add(53);
        prime_num.add(59);
        prime_num.add(61);
        prime_num.add(67);
        prime_num.add(71);
        prime_num.add(73);
        prime_num.add(79);
        prime_num.add(83);
        prime_num.add(89);
        prime_num.add(97);

    }

    public int numPrimeArrangements(int n) {
        int prime = getPrimeNums(n);
        int no_prime = n - prime;
        long n1 = factorial(prime);
        long n2 = factorial(no_prime);
        double max = Math.pow(10, 9) + 7;
        long result = n1 * n2;
        return (int) (result > Integer.MAX_VALUE ? result % max : result);
    }

    private long factorial(int prime) {
        long num = prime;
        long i = prime;
        while (i != 1) {
            num = num * (i - 1);
            i--;
        }
        return num;
    }

    private int getPrimeNums(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (prime_num.contains(i)) {
                sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        PrimeArrangements main = new PrimeArrangements();
        System.out.println(main.factorial(75));;
        System.out.println(main.numPrimeArrangements(5) == 12);
        System.out.println(main.numPrimeArrangements(100) == 682289015);
    }
}