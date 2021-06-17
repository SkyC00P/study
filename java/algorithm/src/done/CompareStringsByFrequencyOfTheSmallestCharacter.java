package done;

import java.util.Arrays;

public class CompareStringsByFrequencyOfTheSmallestCharacter {
    /**
     * Runtime: 22 ms, faster than 40.12% of Java online submissions for Compare
     * Strings by Frequency of the Smallest Character. Memory Usage: 39.3 MB, less
     * than 97.99% of Java online submissions for Compare Strings by Frequency of
     * the Smallest Character.
     */
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] arrQuery = new int[queries.length];
        int[] arrWord = new int[words.length];

        findTheSmallestCharacter(queries, arrQuery);
        // System.out.println(Arrays.toString(arrQuery));
        findTheSmallestCharacter(words, arrWord);
        // System.out.println(Arrays.toString(arrWord));
        int[] arr = new int[arrQuery.length];
        for (int i = 0; i < arrQuery.length; i++) {
            int n = 0;
            for (int j = 0; j < arrWord.length; j++) {
                if (arrWord[j] > arrQuery[i]) {
                    n++;
                }
            }
            arr[i] = n;
        }
        return arr;
    }

    private void findTheSmallestCharacter(String[] queries, int[] arrQuery) {
        for (int i = 0; i < queries.length; i++) {
            String s = queries[i];
            char[] chs = s.toCharArray();
            if (chs.length == 1) {
                arrQuery[i] = 1;
                continue;
            }
            Arrays.sort(chs);
            for (int j = 1; j < chs.length; j++) {
                if (chs[j] != chs[0]) {
                    arrQuery[i] = j;
                    break;
                } else if (j + 1 == chs.length) {
                    arrQuery[i] = j + 1;
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        CompareStringsByFrequencyOfTheSmallestCharacter main = new CompareStringsByFrequencyOfTheSmallestCharacter();
        int[] arr = main.numSmallerByFrequency(new String[] { "cbd" }, new String[] { "zaaaz" });
        System.out.println(Arrays.toString(arr));
        // [6,1,1,2,3,3,3,1,3,2]
        int[] arr_1 = main.numSmallerByFrequency(
                new String[] { "bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab",
                        "bbabbaabb" },
                new String[] { "aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab",
                        "aa" });
        System.out.println(Arrays.toString(arr_1));

        // [9,9,5,7,5,9,9,5,7,5,1,9,1,2]
        int[] arr_2 = main.numSmallerByFrequency(
                new String[] { "ba", "b", "aaa", "bbbabba", "aaa", "b", "b", "baabbbab", "abba", "abbabab", "aaaaa",
                        "b", "baaaaabbb", "baabbaa" },
                new String[] { "bbaa", "bbb", "aabaa", "baabbaab", "aaabbb", "aabbaabb", "ba", "aaaaabb", "abbbb",
                        "baaaaabaaa", "a", "bab", "aba", "bba" });
        System.out.println(Arrays.toString(arr_2));
    }
}
