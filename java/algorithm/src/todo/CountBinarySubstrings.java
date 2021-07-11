package todo;

public class CountBinarySubstrings {
    public int countBinarySubstrings(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int j = i + 1;
            int count = 0;
            while (j != s.length() && ch == s.charAt(j)) {
                j = j + 1;
                count++;
            }

            while (count != 0 && ch != s.charAt(j)) {
                j++;
                count--;
            }
            if (count == 0) sum += 1;
        }
        return sum;
    }

    public static void main(String[] args) {
        CountBinarySubstrings main = new CountBinarySubstrings();
        int i = main.countBinarySubstrings("00110011");
        System.out.println(i);
    }
}
