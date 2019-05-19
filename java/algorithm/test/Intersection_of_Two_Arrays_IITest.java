import org.junit.jupiter.api.Test;
import utils.ArrayUtils;

import static org.junit.jupiter.api.Assertions.*;

class Intersection_of_Two_Arrays_IITest {

    Intersection_of_Two_Arrays_II solution = new Intersection_of_Two_Arrays_II();

    @Test
    void intersect() {
        int[] n1 = new int[]{1, 2, 2, 1};
        int[] n2 = new int[]{2, 2};
        int[] n3 = solution.intersect(n1, n2);

        assertArrayEquals(new int[]{2, 2}, n3);

        n1 = new int[]{4, 9, 5};
        n2 = new int[]{9, 4, 9, 8, 4};
        n3 = solution.intersect(n1, n2);
        assertTrue(ArrayUtils.equalsIgnoreSore(new int[]{4, 9}, n3));

        n1 = new int[]{4, 9, 5};
        n2 = new int[]{9, 4, 9, 8, 4};
        n3 = solution.intersect(n1, n2);
        assertTrue(ArrayUtils.equalsIgnoreSore(new int[]{4, 9}, n3));

    }
}