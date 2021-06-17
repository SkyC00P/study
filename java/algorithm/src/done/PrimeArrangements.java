package done;

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

    /**
     * Runtime: 1 ms, faster than 37.16% of Java online submissions for Prime Arrangements.
     * Memory Usage: 36 MB, less than 30.60% of Java online submissions for Prime Arrangements.
     */
    public int numPrimeArrangements(int n) {
        if (n < 2) return 1;
        int prime = getPrimeNums(n);
        int no_prime = n - prime;

        long res = 1;
        for (int i = prime; i > 0; i--) {
            res = res * i;
            res %= 1000000007;
        }
        for (int i = no_prime; i > 0; i--) {
            res = res * i;
            res %= 1000000007;
        }
        return (int) res;
    }

    private int getPrimeNums(int n) {
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            if (prime_num.contains(i)) {
                sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        PrimeArrangements main = new PrimeArrangements();
        System.out.println(main.getPrimeNums(11));
        System.out.println(main.numPrimeArrangements_answer(11) == 86400);
        System.out.println(main.numPrimeArrangements_answer(100) == 682289015);
    }

    public int numPrimeArrangements_answer(int n) {
        if (n < 2) {
            return 1;
        }
        long res = 1;
        int prime = 1;
        int notPrime = 1;

        for (int i = 3; i <= n; i++) {
            if (isPrime(i)) {
                prime++;
            } else {
                notPrime++;
            }
        }
        System.out.println(prime + "-" + notPrime);
        for (int i = prime; i > 0; i--) {
            res *= i;
            res %= 1000000007;
        }
        for (int i = notPrime; i > 0; i--) {
            res *= i;
            res %= 1000000007;
        }
        return (int) res;
    }

    public boolean isPrime(int num) {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
