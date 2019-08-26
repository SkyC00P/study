import utils.ArrayUtils;

public class Construct_the_Rectangle {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Construct the Rectangle.
     * Memory Usage: 33.6 MB, less than 8.33% of Java online submissions for Construct the Rectangle.
     */
    public int[] constructRectangle(int area) {
        int pow = (int) Math.sqrt(area);
        while (area % pow != 0) {
            pow--;
        }
        int i = area / pow;
        return new int[]{Math.max(pow, i), Math.min(pow, i)};
    }

    public static void main(String[] args) {
        Construct_the_Rectangle test = new Construct_the_Rectangle();
        boolean isEqual = ArrayUtils.equals(test.constructRectangle(4), new int[]{2, 2});
        System.out.println(isEqual);
    }
}
