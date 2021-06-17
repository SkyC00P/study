package done;

public class DetectCapital {
    /**
     * Runtime: 1 ms, faster than 99.86% of Java online submissions for Detect Capital.
     * Memory Usage: 39.2 MB, less than 10.71% of Java online submissions for Detect Capital.
     */
    public boolean detectCapitalUse(String word) {
        if (word == null || word.isEmpty()) {
            return false;
        }
        if (word.length() == 1) {
            return true;
        }
        boolean capital_1 = word.charAt(0) >= 'A' && word.charAt(0) <= 'Z';
        boolean capital_2 = word.charAt(1) >= 'A' && word.charAt(1) <= 'Z';
        if (word.length() == 2) {
            return capital_1 || !capital_2;
        }
        boolean remain_eq = true;
        for (int i = 2; i < word.length(); i++) {
            char ch = word.charAt(i);
            boolean capital = ch >= 'A' && ch <= 'Z';
            if (capital != capital_2) {
                remain_eq = false;
                break;
            }
        }
        if (remain_eq){
            return capital_1 || !capital_2;
        }else {
            return false;
        }
    }

    public static void main(String[] args) {
        DetectCapital detectCapital = new DetectCapital();
        System.out.println(detectCapital.detectCapitalUse("Leetcode"));
        System.out.println();
    }
}
