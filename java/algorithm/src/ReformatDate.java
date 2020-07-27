import java.util.HashMap;
import java.util.Map;

public class ReformatDate {
    Map<String, String> pairs = new HashMap<>();

    {
        pairs.put("Jan", "01");
        pairs.put("Feb", "02");
        pairs.put("Mar", "03");
        pairs.put("Apr", "04");
        pairs.put("May", "05");
        pairs.put("Jun", "06");
        pairs.put("Jul", "07");
        pairs.put("Aug", "08");
        pairs.put("Sep", "09");
        pairs.put("Oct", "10");
        pairs.put("Nov", "11");
        pairs.put("Dec", "12");
    }

    /**
     * Runtime: 11 ms, faster than 46.26% of Java online submissions for Reformat Date.
     * Memory Usage: 38.3 MB, less than 100.00% of Java online submissions for Reformat Date.
     */
    public String reformatDate(String date) {

        String[] arr = date.split(" ");
        boolean ch1 = Character.isDigit(arr[0].charAt(0));
        boolean ch2 = Character.isDigit(arr[0].charAt(1));
        if (ch1 && ch2) {
            return arr[2] + "-" + pairs.get(arr[1]) + "-" + arr[0].charAt(0) + arr[0].charAt(1);
        } else {
            return arr[2] + "-" + pairs.get(arr[1]) + "-" + 0 + arr[0].charAt(0);
        }
    }

    public static void main(String[] args) {
        ReformatDate reformatDate = new ReformatDate();
        System.out.println(reformatDate.reformatDate("20th Oct 2052").equals("2052-10-20"));
        System.out.println(reformatDate.reformatDate("6th Jun 1933").equals("1933-06-06"));
        System.out.println(reformatDate.reformatDate("26th May 1960").equals("1960-05-26"));
    }
}
