package done;

public class GreatestCommonDivisorOfStrings {
    /**
     * Runtime: 1 ms, faster than 50.43% of Java online submissions for Greatest Common Divisor of Strings.
     * Memory Usage: 38.6 MB, less than 93.11% of Java online submissions for Greatest Common Divisor of Strings.
     */
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) return ""; // 1st option

        if (str1.length() < str2.length()) {
            return gcdOfStrings(str2, str1);
        }

        //  2nd option - if (!str1.startsWith(str2)) return "";

        String reminder = str1.substring(str2.length());
        if (reminder.isEmpty()) {
            return str2;
        }

        return gcdOfStrings(str2, reminder);
    }

    public static void main(String[] args) {
        GreatestCommonDivisorOfStrings main = new GreatestCommonDivisorOfStrings();
        System.out.println(main.gcdOfStrings("ABC", "ABCABC"));
    }
}
