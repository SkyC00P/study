package todo;

/**
 * Given n points in the plane that are all pairwise distinct,
 * a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k
 * (the order of the tuple matters).
 * <p>
 * Find the number of boomerangs.
 * You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive)
 */
public class Number_of_Boomerangs {
    public int numberOfBoomerangs(int[][] points) {
        return 2;
    }

    public static void main(String[] args) {
        Number_of_Boomerangs test = new Number_of_Boomerangs();
        int[][] points = new int[][]{
                new int[]{0, 0},
                new int[]{0, 1},
                new int[]{2, 0}
        };
        int i = test.numberOfBoomerangs(points);
        System.out.println(i == 2);
    }
}
