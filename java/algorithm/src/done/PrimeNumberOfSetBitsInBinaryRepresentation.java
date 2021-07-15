package done;

import java.util.HashSet;
import java.util.Set;

public class PrimeNumberOfSetBitsInBinaryRepresentation {

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
    }

    /**
     * Runtime: 7 ms, faster than 71.87% of Java online submissions for Prime Number of Set Bits in Binary Representation.
     * Memory Usage: 36 MB, less than 51.45% of Java online submissions for Prime Number of Set Bits in Binary Representation.
     */
    public int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            int bitCount = Integer.bitCount(i);
            if (prime_num.contains(bitCount)) count++;
        }
        return count;
    }
}
