public class CountAndSay {
    public String countAndSay(int n) {
        if (n >= 1 && n <= 30) {
            StringBuilder sb = new StringBuilder("1");
            for (int i = 1; i < n; i++) {
                String s = sb.toString();
            }
            return sb.toString();
        }
        return "1";
    }

    public static void main(String[] args) {
        CountAndSay solution = new CountAndSay();
        System.out.println(solution.countAndSay(1).equals("1"));
        System.out.println(solution.countAndSay(2).equals("11"));
        System.out.println(solution.countAndSay(3).equals("21"));
        System.out.println(solution.countAndSay(4).equals("1211"));
        System.out.println(solution.countAndSay(5).equals("111221"));
        System.out.println(solution.countAndSay(6).equals("312211"));

    }
}
