package todo;
public class K_diffPairs_in_anArray {
    public int findPairs(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int n = nums[i] - nums[j];
                n = n > 0 ? n : -n;
                if (n == k) {
                    sum++;
                }
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        K_diffPairs_in_anArray main = new K_diffPairs_in_anArray();
        System.out.println(main.findPairs(new int[]{3, 1, 4, 1, 5}, 2) == 2);
    }
}