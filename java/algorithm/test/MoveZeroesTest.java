import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MoveZeroesTest {

    MoveZeroes solution = new MoveZeroes();

    @Test
    void moveZeroes() {
        int[] arr = new int[]{0, 1, 0, 3, 12};
        solution.moveZeroes(arr);
        assertArrayEquals(new int[]{1, 3, 12, 0, 0}, arr);

        arr = new int[]{0};
        solution.moveZeroes(arr);
        assertArrayEquals(new int[]{0}, arr);

        arr = new int[]{1};
        solution.moveZeroes(arr);
        assertArrayEquals(new int[]{1}, arr);


    }
}