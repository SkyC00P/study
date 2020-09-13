

public class MakeTheStringGreat {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Make The
     * String Great. Memory Usage: 39.6 MB, less than 55.66% of Java online
     * submissions for Make The String Great.
     */
    public String makeGood(String s) {
        StringBuilder sb = new StringBuilder();
        char[] chs = s.toCharArray();
        boolean check = false;
        for (int i = 0; i < chs.length; i++) {
            char ch = chs[i];
            if (i + 1 < chs.length && Math.abs(chs[i + 1] - ch) == 32) {
                i++;
                check = true;
                continue;
            }
            sb.append(ch);
        }
        return check ? makeGood(sb.toString()) : sb.toString();
    }

    public static void main(String[] args) {
        MakeTheStringGreat main = new MakeTheStringGreat();
        System.out.println(main.makeGood("abBAcC"));
        ;
    }
}