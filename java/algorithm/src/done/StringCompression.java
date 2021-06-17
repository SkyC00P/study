package done;

/**
 * Given an array of characters, compress it in-place.
 * <p>
 * The length after compression must always be smaller than or equal to the
 * original array.
 * <p>
 * Every element of the array should be a character (not int) of length 1.
 * <p>
 * After you are done modifying the input array in-place, return the new length
 * of the array.
 * <p>
 * <p>
 * Follow up: Could you solve it using only O(1) extra space?
 */
public class StringCompression {

    public int compress(char[] chars) {
        int anchor = 0, write = 0;
        for (int read = 0; read < chars.length; read++) {
            if (read + 1 == chars.length || chars[read + 1] != chars[read]) {
                chars[write++] = chars[anchor];
                if (read > anchor) {
                    for (char c: ("" + (read - anchor + 1)).toCharArray()) {
                        chars[write++] = c;
                    }
                }
                anchor = read + 1;
            }
        }
        return write;
    }

    /**
     * Runtime: 2 ms, faster than 8.73% of Java online submissions for String Compression.
     * Memory Usage: 36.4 MB, less than 100.00% of Java online submissions for String Compression.
     */
    public int compress1(char[] chars) {
        if (chars.length == 1) return 1;

        final int mask = 0xff;
        int len = chars.length;
        for (int i = 0; i < chars.length; ) {
            int count = 1;
            for (int j = i + 1; j < chars.length; j++) {
                if (chars[j] == chars[i]) {
                    count++;
                    chars[j] = mask;
                } else {
                    break;
                }
            }
            if (count > 1) {
                char[] chs = IntToChars(count);
                System.arraycopy(chs, 0, chars, i + 1, chs.length);
                len = len - (count - 1 - chs.length);
            }
            i = i + count;
        }

        for (int i = 0, j = 0; i < chars.length; i++, j++) {
            chars[i] = chars[j];
            if (chars[i] == mask) {
                j = j > i ? j : i + 1;
                while (j < chars.length && chars[j] == mask) {
                    j++;
                }
                chars[i] = chars[j];
            }
            if (i == len - 1) break;
        }
        return len;
    }

    private char[] IntToChars(int count) {
        StringBuilder sb = new StringBuilder();

        while (count != 0) {
            sb.insert(0, count % 10);
            count = count / 10;
        }

        return sb.toString().toCharArray();
    }

}
