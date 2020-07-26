public class ShuffleString {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Shuffle String.
     * Memory Usage: 39.1 MB, less than 100.00% of Java online submissions for Shuffle String.
     */
    public String restoreString(String s, int[] indices) {
        char[] shuffleArr = new char[s.length()];

        for (int i = 0; i < indices.length; i++) {
            int index = indices[i];
            shuffleArr[index] = s.charAt(i);
        }
        return new String(shuffleArr);
    }

    /**
     * Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
     * Output: "leetcode"
     */
    public static void main(String[] args) {
        ShuffleString shuffleString = new ShuffleString();
        System.out.println("leetcode".equals(shuffleString.restoreString("codeleet", new int[]{4, 5, 6, 7, 0, 2, 1, 3})));
        System.out.println("abc".equals(shuffleString.restoreString("abc", new int[]{0, 1, 2})));
        System.out.println("nihao".equals(shuffleString.restoreString("aiohn", new int[]{3, 1, 4, 2, 0})));
        System.out.println("arigatou".equals(shuffleString.restoreString("aaiougrt", new int[]{4, 0, 2, 6, 7, 3, 1, 5})));
        System.out.println("rat".equals(shuffleString.restoreString("art", new int[]{1, 0, 2})));
    }
}
