package done;

public class GoatLatin {
    /**
     * Runtime: 4 ms, faster than 58.41% of Java online submissions for Goat Latin.
     * Memory Usage: 37.5 MB, less than 78.09% of Java online submissions for Goat Latin.
     */
    public String toGoatLatin(String sentence) {
        StringBuilder sb = new StringBuilder();
        int index = 1;
        StringBuilder word = new StringBuilder();
        for (char ch : sentence.toCharArray()) {
            if (ch == ' ') {
                getWord(sb, word, index);
                index++;
                word = new StringBuilder();
            } else {
                word.append(ch);
            }
        }
        getWord(sb, word, index);
        return sb.deleteCharAt(sb.length() - 1).toString();
    }

    private void getWord(StringBuilder sb, StringBuilder word, int index) {
        if ("aeiouAEIOU".contains(word.charAt(0) + "")) {
            word.append("ma");
        } else {
            word.append(word.charAt(0)).deleteCharAt(0).append("ma");
        }
        for (int i = 0; i < index; i++) {
            word.append("a");
        }
        sb.append(word.toString()).append(" ");
    }

    public static void main(String[] args) {
        GoatLatin main = new GoatLatin();
        String txt = main.toGoatLatin("I speak Goat Latin");
        // "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
        System.out.println(txt);
    }
}
