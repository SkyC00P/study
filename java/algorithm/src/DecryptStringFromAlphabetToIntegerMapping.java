

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class DecryptStringFromAlphabetToIntegerMapping {

    private Map<String, Character> MAP = new HashMap<>();

    {
        MAP.put("1", 'a');
        MAP.put("2", 'b');
        MAP.put("3", 'c');
        MAP.put("4", 'd');
        MAP.put("5", 'e');
        MAP.put("6", 'f');
        MAP.put("7", 'g');
        MAP.put("8", 'h');
        MAP.put("9", 'i');
        MAP.put("10#", 'j');
        MAP.put("11#", 'k');
        MAP.put("12#", 'l');
        MAP.put("13#", 'm');
        MAP.put("14#", 'n');
        MAP.put("15#", 'o');
        MAP.put("16#", 'p');
        MAP.put("17#", 'q');
        MAP.put("18#", 'r');
        MAP.put("19#", 's');
        MAP.put("20#", 't');
        MAP.put("21#", 'u');
        MAP.put("22#", 'v');
        MAP.put("23#", 'w');
        MAP.put("24#", 'x');
        MAP.put("25#", 'y');
        MAP.put("26#", 'z');
    }

    /**
     * Runtime: 9 ms, faster than 14.98% of Java online submissions for Decrypt
     * String from Alphabet to Integer Mapping. Memory Usage: 39.6 MB, less than
     * 21.81% of Java online submissions for Decrypt String from Alphabet to Integer
     * Mapping.
     */
    public String freqAlphabets(String s) {
        Deque<Character> deque = new ArrayDeque<>();
        char[] chs = s.toCharArray();
        for (char ch : chs) {
            if (ch == '#') {
                char c2 = deque.pop();
                char c1 = deque.pop();
                String key = Character.toString(c1) + Character.toString(c2) + "#";
                deque.push(MAP.get(key));
            } else {
                deque.push(ch);
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!deque.isEmpty()) {
            char c = deque.removeLast();
            Character ch = MAP.get(c + "");
            if (ch == null) {
                sb.append(c);
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        DecryptStringFromAlphabetToIntegerMapping main = new DecryptStringFromAlphabetToIntegerMapping();
        System.out.println(main.freqAlphabets("10#11#12"));
    }
}
