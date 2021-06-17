package done;

import java.util.Objects;

public class Reverse_String_II {
    /**
     * Runtime: 1 ms, faster than 78.66% of Java online submissions for Reverse String II.
     * Memory Usage: 39.1 MB, less than 64.78% of Java online submissions for Reverse String II.
     */
    public String reverseStr(String s, int k) {
        char[] chs = s.toCharArray();
        char[] r_chs = new char[chs.length];

        boolean reverse = true;
        int index = 0;
        do {
            if (reverse) {
                index = putChar(r_chs, chs, k, index);
                reverse = false;
            } else {
                index = putStr(r_chs, chs, k, index);
                reverse = true;
            }
        } while (index != chs.length);

        return new String(r_chs);
    }

    private int putStr(char[] r_chs, char[] chs, int k, int index) {
        while (k != 0 && index < chs.length) {
            r_chs[index] = chs[index];
            index++;
            k--;
        }
        return index;
    }

    private int putChar(char[] r_chs, char[] chs, int k, int index) {
        int tail = Math.min(index + k - 1, r_chs.length - 1);
        while (k != 0 && index < chs.length) {
            r_chs[index] = chs[tail];
            index++;
            tail--;
            k--;
        }
        return index;
    }

    public static void main(String[] args) {
        Reverse_String_II q = new Reverse_String_II();
        System.out.println(q.reverseStr("abcdefg", 3));
        System.out.println(Objects.equals("bacdfeg", q.reverseStr("abcdefg", 2)));
        System.out.println(Objects.equals("bac", q.reverseStr("abc", 2)));
        System.out.println(Objects.equals("bacd", q.reverseStr("abcd", 2)));
        System.out.println(Objects.equals("dcba", q.reverseStr("abcd", 4)));
        System.out.println(Objects.equals("dcba", q.reverseStr("abcd", 5)));
    }
}
