import java.time.LocalDate;

public class Day_of_theWeek {
    /**
     * Runtime: 1 ms, faster than 31.16% of Java online submissions for Day of the
     * Week. Memory Usage: 37.2 MB, less than 50.31% of Java online submissions for
     * Day of the Week.
     */
    public String dayOfTheWeek(final int day, final int month, final int year) {
        final LocalDate date = LocalDate.of(year, month, day);
        switch (date.getDayOfWeek()) {
            case MONDAY:
                return "Monday";
            case TUESDAY:
                return "Tuesday";
            case WEDNESDAY:
                return "Wednesday";
            case THURSDAY:
                return "Thursday";
            case FRIDAY:
                return "Friday";
            case SATURDAY:
                return "Saturday";
            case SUNDAY:
                return "Sunday";
            default:
                return "";
        }
    }
}