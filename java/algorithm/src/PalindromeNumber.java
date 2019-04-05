/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 */
public class PalindromeNumber {

    /**
     * Runtime: 72 ms, faster than 94.44% of Java online submissions for Palindrome Number.
     * Memory Usage: 40.2 MB, less than 74.39% of Java online submissions for Palindrome Number
     */
    public boolean isPalindrome(int x) {

        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
    }

    /**
     * Runtime: 76 ms, faster than 72.00% of Java online submissions for Palindrome Number.
     * Memory Usage: 40.7 MB, less than 32.39% of Java online submissions for Palindrome Number.
     */
    public boolean isPalindrome_1(int x) {
        String s = String.valueOf(x);
        return new StringBuilder(s).reverse().toString().equals(s);
    }

    public static void main(String[] args) {

        PalindromeNumber solution = new PalindromeNumber();
        System.out.println(!solution.isPalindrome(123));
        System.out.println(solution.isPalindrome(121));
        System.out.println(!solution.isPalindrome(-121));
        System.out.println(solution.isPalindrome(1221));
    }
}
