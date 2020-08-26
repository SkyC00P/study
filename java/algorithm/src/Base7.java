public class Base7{

    /**
     * Runtime: 1 ms, faster than 91.56% of Java online submissions for Base 7.
     * Memory Usage: 37.2 MB, less than 58.09% of Java online submissions for Base 7
     */
    public String convertToBase7(final int num) {
        int n = num > 0 ? num : -num;
        final StringBuilder sb = new StringBuilder();

        do {
            final int n1 = n / 7;
            final int n2 = n % 7;
            sb.append(n2);
            n = n1;
        } while (n != 0);

        final String s_7 = sb.reverse().toString();
        return num >= 0 ? s_7 : "-" + s_7;
    }
}