package done;

public class ValidMountainArray {
    /**
     * Runtime: 2 ms, faster than 33.24% of Java online submissions for Valid Mountain Array.
     * Memory Usage: 40.3 MB, less than 21.61% of Java online submissions for Valid Mountain Array.
     */
    public boolean validMountainArray(int[] arr) {
        if (arr.length < 3) return false;
        boolean up = true;
        for (int i = 1; i < arr.length - 1; i++) {
            int n2 = arr[i];
            int n1 = arr[i - 1];
            int n3 = arr[i + 1];
            if (n1 == n2 || n2 == n3) return false;
            if (n2 > n1 && n2 > n3) {
                up = false;
            } else {
                if (up) {
                    if (!(n2 > n1 && n2 < n3)) {return false;}
                } else {
                    if (!(n2 < n1 && n2 > n3)) {return false;}
                }
            }
        }
        return !up;
    }

    public static void main(String[] args) {
        ValidMountainArray main = new ValidMountainArray();
        System.out.println(main.validMountainArray(new int[]{0, 1, 2, 4, 2, 1}));
    }
}
