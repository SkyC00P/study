import java.util.ArrayList;
import java.util.List;

public class FizzBuzz {

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Fizz Buzz.
     * Memory Usage: 37.2 MB, less than 99.97% of Java online submissions for Fizz Buzz.
     */
    public List<String> fizzBuzz(int n) {
        List<String> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            boolean _3 = i % 3 == 0;
            boolean _5 = i % 5 == 0;

            if (_3 && _5) {
                list.add("FizzBuzz");
            } else if (_3) {
                list.add("Fizz");
            } else if (_5) {
                list.add("Buzz");
            } else {
                list.add(i + "");
            }
        }
        return list;
    }
}
