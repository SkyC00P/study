import java.util.ArrayList;
import java.util.List;

/**
 * A binary watch has 4 LEDs on the top which represent the hours (0-11),
 * and the 6 LEDs on the bottom represent the minutes (0-59)
 * <p>
 * Each LED represents a zero or one, with the least significant bit on the right.
 * <p>
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02"
 * <p>
 * Given a non-negative integer n which represents the number of LEDs that are currently on,
 * return all possible times the watch could represent
 */
public class BinaryWatch {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Watch.
     * Memory Usage: 34.7 MB, less than 100.00% of Java online submissions for Binary Watch.
     */
    public List<String> readBinaryWatch(int num) {
        List<String> list = new ArrayList<>();
        if (num < 0 || num > 8) {
            return list;
        }
        List<Integer> splitArr = splitArr(num);
        for (int i : splitArr) {
            for (String h : hour[i]) {
                for (String m : minute[num - i]) {
                    String s = h + ":" + m;
                    list.add(s);
                }
            }
        }
        return list;
    }

    private List<Integer> splitArr(int num) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                if (i + j == num) {
                    list.add(i);
                }
            }
        }
        return list;
    }

    static String[][] hour = new String[][]{
            new String[]{"0"},
            new String[]{"1", "2", "4", "8"},
            new String[]{"3", "6", "5", "9", "10"},
            new String[]{"11", "7"}
    };

    static String[][] minute = new String[][]{
            new String[]{"00"},
            new String[]{"01", "02", "04", "08", "16", "32"},
            new String[]{"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"},
            new String[]{"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"},
            new String[]{"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"},
            new String[]{"59", "31", "47", "55"}
    };

    public static void main(String[] args) {
        int sum = 0;
        for (String[] arr : minute) {
            sum += arr.length;
        }
        System.out.println(sum);
    }
}


