package todo;

/**
 * 933
 */
public class LongPressedName {
    /**
     * K != -1 && A[i] == B[k]  ?
     *   Y --> change j = k and look for next k
     *       find K ?
     *         --> Y
     *         --> N K== -1
     *   N --> A[i] == B[j] && m > 1 ?
     *       --> Y change m = m-1
     *       --> N return false
     */
    public boolean isLongPressedName(String name, String typed) {
        int[] arr = new int[3];
        for (int i = 0; i < name.length(); i++) {
            if (notLongPressedName(name, typed, i, arr)) {
                return false;
            }
        }
        return true;
    }

    private boolean notLongPressedName(String name, String typed, int i, int[] arr) {
        final int j = arr[0];
        final int k = arr[1];
        final int m = arr[2];
        if (k != -1 && name.charAt(i) == typed.charAt(k)) {
            arr[0] = k;
            arr[1] = -1;
            arr[2] = 0;
            char ch = typed.charAt(k);
            for (int l = k + 1; l < typed.length(); l++) {
                if (ch != typed.charAt(l)) {
                    arr[1] = l;
                    break;
                } else {
                    arr[2] = arr[2] + 1;
                }
            }
        } else {
            if (name.charAt(i) == typed.charAt(j) && m >= 1) {
                arr[2] = arr[2] - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        LongPressedName main = new LongPressedName();
        // true
//        System.out.println(main.isLongPressedName("alex", "aaleex"));
        // false
//        System.out.println(main.isLongPressedName("saeed", "ssaaedd"));
        //true
//        System.out.println(main.isLongPressedName("leelee", "lleeelee"));
        // false This is failed.
        System.out.println(main.isLongPressedName("alex", "aaleexa"));
    }
}
