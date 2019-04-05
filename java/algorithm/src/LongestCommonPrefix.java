public class LongestCommonPrefix {

    /**
     * Runtime: 1 ms, faster than 98.12% of Java online submissions for Longest Common Prefix.
     * Memory Usage: 38.8 MB, less than 20.63% of Java online submissions for Longest Common Prefix.
     */
    public String longestCommonPrefix(String[] strs) {

        if(strs.length == 0) return "";
        StringBuilder sb = new StringBuilder();
        int min = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            if (strs[i].length() < min) {
                min = strs[i].length();
            }
        }

        loop:
        for (int i = 0; i < min; i++) {
            boolean isEqual = true;
            for (int j = 0; j < strs.length - 1; j++) {
                if (strs[j].charAt(i) - strs[j + 1].charAt(i) != 0) {
                    isEqual = false;
                    break loop;
                }
            }
            sb.append(strs[0].charAt(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        LongestCommonPrefix solution = new LongestCommonPrefix();
        System.out.println(solution.longestCommonPrefix(new String[]{"flower", "flow", "flight"}).equals("fl"));
        System.out.println(solution.longestCommonPrefix(new String[]{"dog", "racecar", "car"}).equals(""));
    }
}
