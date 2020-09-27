public class CheckIfAWordOccursAsAPrefixOfAnyWordInASentence {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Check If a
     * Word Occurs As a Prefix of Any Word in a Sentence. Memory Usage: 36.8 MB,
     * less than 97.14% of Java online submissions for Check If a Word Occurs As a
     * Prefix of Any Word in a Sentence.
     */
    public int isPrefixOfWord(String sentence, String searchWord) {
        String words[] = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (words[i].startsWith(searchWord)) {
                return i + 1;
            }
        }
        return -1;
    }
}
