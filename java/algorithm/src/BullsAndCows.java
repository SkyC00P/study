import java.util.ArrayList;
import java.util.List;

public class BullsAndCows {
    /**
     * Runtime: 5 ms, faster than 31.74% of Java online submissions for Bulls and Cows.
     * Memory Usage: 36.4 MB, less than 100.00% of Java online submissions for Bulls and Cows
     */
    public String getHint(String secret, String guess) {
        int nA = 0;
        int nB = 0;

        List<Character> remain_s = new ArrayList<>();
        List<Character> remain_g = new ArrayList<>();

        for (int i = 0, j = 0; i < secret.length(); i++, j++) {

            if (secret.charAt(i) == guess.charAt(j)) {
                nA++;
            } else {
                remain_s.add(secret.charAt(i));
                remain_g.add(guess.charAt(j));
            }

        }

        for (char ch : remain_s) {
            if (remain_g.remove(Character.valueOf(ch))) {
                nB++;
            }
        }

        return nA + "A" + nB + "B";
    }

    public static void main(String[] args) {
        BullsAndCows test = new BullsAndCows();
        String s = test.getHint("1807", "7810");
        System.out.println(s);
        s = test.getHint("1123", "0111");
        System.out.println(s);
        s = test.getHint("011", "110"); // "1A2B"
        System.out.println(s);
    }
}
