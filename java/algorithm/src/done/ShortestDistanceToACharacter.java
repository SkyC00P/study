package done;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

/**
 * 821
 */
public class ShortestDistanceToACharacter {
    /**
     * Runtime: 1 ms, faster than 97.62% of Java online submissions for Shortest Distance to a Character.
     * Memory Usage: 39.3 MB, less than 34.85% of Java online submissions for Shortest Distance to a Character.
     */
    public int[] shortestToChar(String s, char c) {
        int[] arr = new int[s.length()];
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            boolean tch = s.charAt(i) == c;
            arr[i] = tch ? 0 : -1;
            if (tch) queue.add(i);
        }
        if (queue.isEmpty()) return null;

        int tail = queue.poll();
        for (int i = 0; i < tail; i++) {
            arr[i] = tail - i;
        }

        if (queue.isEmpty()) {
            int j = 1;
            for (int i = tail + j; i < s.length(); i++) {
                arr[i] = j;
                j++;
            }
            return arr;
        }

        while (!queue.isEmpty()) {
            int head = tail;
            tail = queue.poll();
            for (int i = 1; tail - head > 1 && i <= (tail - head) / 2; i++) {
                arr[head + i] = i;
                arr[tail - i] = i;
            }
        }
        for (int j = 1; tail + j < s.length(); j++) {
            arr[tail + j] = j;
        }
        return arr;
    }

    //"loveleetcode"
    //"e"
    public static void main(String[] args) {
        ShortestDistanceToACharacter main = new ShortestDistanceToACharacter();
//        System.out.println(Arrays.toString(main.shortestToChar("loveleetcode", 'e')));
        // [1,0,1,-1]
        // "abaa"
        //"b"
//        System.out.println(Arrays.toString(main.shortestToChar("abaa", 'b')));
        //"bbaa"
        //"b"
        System.out.println(Arrays.toString(main.shortestToChar("bbaa", 'b')));
    }
}
