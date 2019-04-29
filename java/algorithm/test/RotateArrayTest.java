import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RotateArrayTest {

    RotateArray solution = new RotateArray();

    @Test
    void rotate() {
        int[] arr = new int[]{1, 2, 3, 4, 5, 6, 7};
        solution.rotate(arr, 3);
        assertArrayEquals(new int[]{5, 6, 7, 1, 2, 3, 4}, arr);

        int[] arr1 = new int[]{-1, -100, 3, 99};
        solution.rotate(arr1, 2);
        assertArrayEquals(new int[]{3, 99, -1, -100}, arr1);

        int[] arr2 = new int[]{-1};
        solution.rotate(arr2, 2);
        assertArrayEquals(new int[]{-1}, arr2);
    }
}