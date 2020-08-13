import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Day_of_theYear {

    /**
     * Runtime: 11 ms, faster than 6.50% of Java online submissions for Day of the
     * Year. Memory Usage: 39 MB, less than 35.04% of Java online submissions for
     * Day of the Year.
     */
    public int dayOfYear(String date) {
        LocalDate localDate = LocalDate.parse(date, DateTimeFormatter.ofPattern("yyyy-MM-dd"));
        return localDate.getDayOfYear();
    }

    public static void main(String[] args) {
        Day_of_theYear day_of_theYear = new Day_of_theYear();
        System.out.println(day_of_theYear.dayOfYear("2019-01-09") == 9);
    }
}