package done;

public class Guess_Number_Higher_or_Lower {


    static class GuessGame {

        private int pick;

        void setPick(int pick) {
            this.pick = pick;
        }

        /**
         * @param num, your guess
         * @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
         * int guess(int num);
         */
        int guess(int num) {
            if (num == pick) return 0;
            return num > pick ? -1 : 1;
        }
    }

    public static class Solution extends GuessGame {

        /**
         * Runtime: 0 ms, faster than 100.00% of Java online submissions for Guess Number Higher or Lower.
         * Memory Usage: 32.4 MB, less than 100.00% of Java online submissions for Guess Number Higher or Lower.
         */
        public int guessNumber(int n) {
            if (guess(n) == 0) return n;
            int g = 0, l = 1, r = n;
            int mid = l + (r - l) / 2;
            while ((g = guess(mid)) != 0) {
                if (g < 0) {
                    r = mid;
                } else {
                    l = mid;
                }
                mid = l + (r - l) / 2;
            }
            return mid;
        }

        public int guessNumber_1(int n){
            int low = 1;
            int high = n;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int res = guess(mid);
                if (res == 0)
                    return mid;
                else if (res < 0)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return -1;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.setPick(6);
        assert solution.guessNumber(10) == 6;
    }
}
