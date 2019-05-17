public class PowerofFour {
    /**
     * Runtime: 1 ms, faster than 85.34% of Java online submissions for Power of Four.
     * Memory Usage: 32.5 MB, less than 44.70% of Java online submissions for Power of Four.
     */
    public boolean isPowerOfFour(int num) {
        if(num < 0 )return false;
        int n = num;
        while( n % 4 == 0){
            n = n / 4;
        }
        return n == 1;
    }
}
