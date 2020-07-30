import java.util.Arrays;

public class CanMakeArithmeticProgressionFromSequence {
    /**
     * Runtime: 3 ms, faster than 24.98% of Java online submissions for Can Make Arithmetic Progression From Sequence.
     * Memory Usage: 39.2 MB, less than 35.19% of Java online submissions for Can Make Arithmetic Progression From Sequence.
     */
    public boolean canMakeArithmeticProgression(int[] arr) {
        if(arr.length == 2){
            return true;
        }
        Arrays.sort(arr);
        for (int i = 0; i + 2 < arr.length; i++) {
            int ai = arr[i];
            int aj = arr[i+1];
            int ak = arr[i+2];
            int n1 = aj - ai;
            int n2 = ak - aj;
            if(n1 != n2){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        CanMakeArithmeticProgressionFromSequence solution = new CanMakeArithmeticProgressionFromSequence();
        System.out.println(solution.canMakeArithmeticProgression(new int[]{3,5,1}));
    }
}