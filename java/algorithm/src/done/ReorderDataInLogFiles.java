package done;

import java.util.Arrays;

public class ReorderDataInLogFiles {
    /*
     * 所有 字母日志 都排在 数字日志 之前。 字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序； 数字日志
     * 应该按原来的顺序排列。
     * Runtime: 25 ms, faster than 5.15% of Java online submissions for
     * Reorder Data in Log Files. Memory Usage: 39.8 MB, less than 69.81% of Java
     * online submissions for Reorder Data in Log Files.
     */
    public String[] reorderLogFiles(final String[] logs) {
        Arrays.sort(logs, (a, b) -> {
            final String[] arr_a = a.split(" ", 2);
            final String[] arr_b = b.split(" ", 2);

            final boolean isNum_a = isNumber(arr_a[1]);
            final boolean isNum_b = isNumber(arr_b[1]);

            if (isNum_a && isNum_b) {
                return 0;
            }
            if (!isNum_a && !isNum_b) {
                int result = arr_a[1].compareTo(arr_b[1]);
                if (result == 0) {
                    return arr_a[0].compareTo(arr_b[0]);
                }
                return result;
            }
            return isNum_a ? 1 : -1;
        });
        return logs;
    }

    private boolean isNumber(final String s) {
        return s.replace(" ", "").matches("[0-9]*");
    }

    public static void main(final String[] args) {
        ReorderDataInLogFiles main = new ReorderDataInLogFiles();
        String[] logs = new String[] { "dig1 8 1 5 1",
                // "let1 art can",
                // "dig2 3 6",
                // "let2 own kit dig",
                // "bet1 art zero",
                "aet1 art zero" };
        System.out.println(Arrays.toString(main.reorderLogFiles(logs)));
    }
}
