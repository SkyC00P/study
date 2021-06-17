package done;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class NumberOfDaysBetweenTwoDates {
    /**
     * Runtime: 12 ms, faster than 20.05% of Java online submissions for Number of Days Between Two Dates.
     * Memory Usage: 38.3 MB, less than 22.53% of Java online submissions for Number of Days Between Two Dates.
     */
    public int daysBetweenDates(String date1, String date2) {
        LocalDate dateBefore = LocalDate.parse(date1);
        LocalDate dateAfter = LocalDate.parse(date2);
        return (int) Math.abs(ChronoUnit.DAYS.between(dateBefore, dateAfter));
    }
}
