import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

/**
 * 英语中的元音字母有 a, e, i, o, u 五个
 */
public class Reverse_Vowels_of_a_String {
    /**
     * Runtime: 10 ms, faster than 14.06% of Java online submissions for Reverse Vowels of a String.
     * Memory Usage: 38.2 MB, less than 73.45% of Java online submissions for Reverse Vowels of a String.
     */
    public String reverseVowels(String s) {
        final Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        vowels.add('A');
        vowels.add('E');
        vowels.add('I');
        vowels.add('O');
        vowels.add('U');

        char[] chs = s.toCharArray();
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < chs.length; i++) {
            if(vowels.contains(chs[i])){
                stack.push(chs[i]);
            }
        }
        for (int i = 0; i < chs.length; i++) {
            if(vowels.contains(chs[i])){
                chs[i] = stack.pop();
            }
        }
        return new String(chs);
    }
}
