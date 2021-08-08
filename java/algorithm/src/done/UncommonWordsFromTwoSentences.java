package done;

import java.util.*;

public class UncommonWordsFromTwoSentences {

    /**
     * Runtime: 2 ms, faster than 80.29% of Java online submissions for Uncommon Words from Two Sentences.
     * Memory Usage: 39.2 MB, less than 35.22% of Java online submissions for Uncommon Words from Two Sentences.
     */
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> m_s1 = new HashMap<>();

        String[] a_s1 = s1.split(" ");
        String[] a_s2 = s2.split(" ");

        for (String s : a_s1) {
            m_s1.put(s, m_s1.getOrDefault(s, 0) + 1);
        }
        for (String s : a_s2) {
            m_s1.put(s, m_s1.getOrDefault(s, 0) + 1);
        }

        Set<String> s_s1 = new HashSet<>();

        for (String k : m_s1.keySet()) {
            if (m_s1.get(k) == 1) {
                if (s_s1.contains(k)) {
                    s_s1.remove(k);
                } else {
                    s_s1.add(k);
                }
            }
        }

        String[] arr = new String[s_s1.size()];
        int i = 0;
        for (String s : s_s1) {
            arr[i++] = s;
        }
        return arr;
    }

    public static void main(String[] args) {
        UncommonWordsFromTwoSentences main = new UncommonWordsFromTwoSentences();
        //"this apple is sweet"
        //"this apple is sour"
        // "s z z z s"
        //"s z ejt"
//        System.out.println(Arrays.toString(main.uncommonFromSentences("this apple is sweet", "this apple is sour")));
        System.out.println(Arrays.toString(main.uncommonFromSentences("s z z z s", "s z ejt")));

    }
}
