import done.Intersection_of_Two_Arrays;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class Intersection_of_Two_ArraysTest {

    Intersection_of_Two_Arrays solution = new Intersection_of_Two_Arrays();

    @Test
    void intersection() {
        int[] n1 = new int[]{1,2,2,1};
        int[] n2 = new int[]{2,2};
        int[] n3 = new int[]{2};
        assertArrayEquals(n3, solution.intersection(n1, n2));

        n1 = new int[]{4,9,5};
        n2 = new int[]{9,4,9,8,4};
        n3 = new int[]{9,4};
        System.out.println(Arrays.toString(solution.intersection(n1, n2)));
        //assertArrayEquals(n3, solution.intersection(n1, n2));
    }
}
