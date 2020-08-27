public class CanPlaceFlowers {
    /**
     * Runtime: 1 ms, faster than 97.08% of Java online submissions for Can Place
     * Flowers. Memory Usage: 41 MB, less than 65.95% of Java online submissions for
     * Can Place Flowers.
     */
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int can_place = 0;
        for (int i = 0; i < flowerbed.length; i++) {
            if (canPla1ce(i, flowerbed)) {
                flowerbed[i] = 1;
                can_place++;
            }
        }
        return can_place >= n;
    }

    private boolean canPla1ce(int i, int[] flowerbed) {
        int left = i - 1;
        int right = i + 1;
        int len = flowerbed.length;
        if (left >= 0 && flowerbed[left] == 1) {
            return false;
        }
        if (right < len && flowerbed[right] == 1) {
            return false;
        }
        return flowerbed[i] == 0;
    }
}