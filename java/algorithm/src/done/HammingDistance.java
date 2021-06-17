package done;

public class HammingDistance {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Hamming Distance.
     * Memory Usage: 33.4 MB, less than 5.09% of Java online submissions for Hamming Distance
     */
    public int hammingDistance(int x, int y) {
        int n = 0;
        int checkSum = x ^ y;
        if (checkSum == 0) return 0;
        for (int i = 0; i < Integer.SIZE; i++) {
            n += checkSum >> i & 1;
        }
        return n;
    }

    public static void main(String[] args) {
        HammingDistance test = new HammingDistance();
        System.out.println(test.hammingDistance(1, 4));
    }
}
