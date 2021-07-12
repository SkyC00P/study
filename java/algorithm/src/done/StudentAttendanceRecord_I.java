package done;

public class StudentAttendanceRecord_I {
    /**
     * Runtime: 1 ms, faster than 31.97% of Java online submissions for Student Attendance Record I.
     * Memory Usage: 39.1 MB, less than 5.44% of Java online submissions for Student Attendance Record I.
     */
    public boolean checkRecord(String s) {
        if (s.contains("LLL")) return false;
        int len = s.length();
        int len_r = s.replace("A", "").length();
        return len - len_r > 2;
    }
}
