package done;

public class BinaryGap {
    /**
     * Runtime: 1 ms, faster than 52.57% of Java online submissions for Binary Gap.
     * Memory Usage: 35.7 MB, less than 77.41% of Java online submissions for Binary Gap.
     */
    public int binaryGap(int n) {
        String binaryRepresentation = Integer.toBinaryString(n); // O(n) space
        int longestDistance = 0;
        int indexOne = binaryRepresentation.indexOf('1');
        for (int i = 1; i < binaryRepresentation.length(); ++i) { // O(n) time
            if (binaryRepresentation.charAt(i) == '1') {
                longestDistance = Math.max(longestDistance, i - indexOne); // greedy
                indexOne = i; // update the index of the most recently seen '1'
            }
        }

        return longestDistance;
    }

    public int binaryGap_fast(int N) {
        int indexOne = -1, longestDistance = 0;
        for (int i = 0; i < 32; ++i) { // 32 bit number so 32 iterations, could also use Integer.toBinaryString(N).length() but the time it takes to convert to binary string is longer than just doing extra iterations for numbers smaller than 32 bits in size
            if (((N >> i) & 1) == 1) { // take the right most bit, use the bitwise 'AND' operator, if result is 1 then bit was a 1
                if (indexOne != -1) // only the first 1 will not trigger this conditional
                    longestDistance = Math.max(longestDistance, i - indexOne); // greedy
                indexOne = i; // update the index of the most recently seen '1'
            }
        }

        return longestDistance;
    }
}
