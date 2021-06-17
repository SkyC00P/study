package done;

public class AddStrings {

    String[][] table = new String[][]{
            new String[]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},// 0
            new String[]{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"},// 1
            new String[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"},// 2
            new String[]{"3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"},// 3
            new String[]{"4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14"},// 4
            new String[]{"5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"},// 5
            new String[]{"6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"},// 6
            new String[]{"7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17"},// 7
            new String[]{"8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18"},// 8
            new String[]{"9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19"},// 9
    };

    /**
     * Runtime: 3 ms, faster than 50.49% of Java online submissions for Add Strings.
     * Memory Usage: 36.3 MB, less than 99.80% of Java online submissions for Add Strings
     */
    public String addStrings11(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int n1, n2 = 0;
        for (n1 = num1.length() - 1, n2 = num2.length() - 1; n1 >= 0 && n2 >= 0; n1--, n2--) {
            String n = table[num1.charAt(n1) - '0'][num2.charAt(n2) - '0' + carry];
            sb.insert(0, n.charAt(n.length() - 1));
            carry = n.length() == 2 ? 1 : 0;
        }

        String remain = n1 < 0 ? num2 : num1;
        int len = n1 >= n2 ? n1 : n2;
        for (int i = len; i >= 0; i--) {
            String n = table[remain.charAt(i) - '0'][carry];
            sb.insert(0, n.charAt(n.length() - 1));
            carry = n.length() == 2 ? 1 : 0;
        }
        return carry == 1 ? sb.insert(0, 1).toString() : sb.toString();
    }

    /**
     * Runtime: 3 ms, faster than 50.49% of Java online submissions for Add Strings.
     * Memory Usage: 36.4 MB, less than 99.80% of Java online submissions for Add Strings
     */
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int n1, n2 = 0;
        for (n1 = num1.length() - 1, n2 = num2.length() - 1; n1 >= 0 && n2 >= 0; n1--, n2--) {
            String n = table[num1.charAt(n1) - '0'][num2.charAt(n2) - '0' + carry];
            sb.append(n.charAt(n.length() - 1));
            carry = n.length() == 2 ? 1 : 0;
        }

        String remain = n1 < 0 ? num2 : num1;
        int len = n1 >= n2 ? n1 : n2;
        for (int i = len; i >= 0; i--) {
            String n = table[remain.charAt(i) - '0'][carry];
            sb.append(n.charAt(n.length() - 1));
            carry = n.length() == 2 ? 1 : 0;
        }
        return carry == 1 ? sb.append(1).reverse().toString() : sb.reverse().toString();
    }

    /**
     * Runtime: 2 ms, faster than 95.05% of Java online submissions for Add Strings.
     * Memory Usage: 36.1 MB, less than 99.80% of Java online submissions for Add Strings.
     */
    public String addStrings_1(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--) {
            int x = i < 0 ? 0 : num1.charAt(i) - '0';
            int y = j < 0 ? 0 : num2.charAt(j) - '0';
            sb.append((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        AddStrings test = new AddStrings();
        System.out.println(test.addStrings("999", "999"));
        System.out.println(test.addStrings("1", "2"));
        System.out.println(test.addStrings("11", "2"));
        System.out.println(test.addStrings("1", "21"));
        System.out.println(test.addStrings("9", "21"));
        System.out.println(test.addStrings("11", "9"));
        System.out.println(test.addStrings("79", "21"));
        System.out.println(test.addStrings("179", "21"));
    }
}
