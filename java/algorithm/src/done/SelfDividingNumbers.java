package done;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SelfDividingNumbers {

    /**
     * Runtime: 12 ms, faster than 5.24% of Java online submissions for Self Dividing Numbers.
     * Memory Usage: 38.9 MB, less than 15.02% of Java online submissions for Self Dividing Numbers.
     */
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i)) {
                list.add(i);
            }
        }
        return list;
    }

    private boolean isSelfDividingNumber(int num) {
        String s = num + "";
        Set<Character> chs = new HashSet<>();
        for (char ch : s.toCharArray()) {
            chs.add(ch);
        }
        for (char ch : chs) {
            switch (ch) {
                case '9':
                    if (num % 9 != 0) return false; break;
                case '8':
                    if (num % 8 != 0) return false; break;
                case '7':
                    if (num % 7 != 0) return false; break;
                case '6':
                    if (num % 6 != 0) return false; break;
                case '5':
                    if (num % 5 != 0) return false; break;
                case '4':
                    if (num % 4 != 0) return false; break;
                case '3':
                    if (num % 3 != 0) return false; break;
                case '2':
                    if (num % 2 != 0) return false; break;
                case '0':
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        SelfDividingNumbers main = new SelfDividingNumbers();
        System.out.println(main.selfDividingNumbers(1, 22));
    }
}
