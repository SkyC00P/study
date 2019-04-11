import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeSortedArrayTest {

    MergeSortedArray solution = new MergeSortedArray();

    @Test
    void merge() {
        int real[] = new int[]{1, 2, 2, 3, 5, 6};
        int nums_1[] = new int[]{1, 2, 3, 0, 0, 0};
        int nums_2[] = new int[]{2, 5, 6};
        solution.merge(nums_1, 3, nums_2, 3);
        assertArrayEquals(real, nums_1);

        real = new int[]{1};
        nums_1 = new int[]{0};
        nums_2 = new int[]{1};
        solution.merge(nums_1, 0, nums_2, 1);
        assertArrayEquals(real, nums_1);

        real = new int[]{1, 2, 3, 4, 5, 6};
        nums_1 = new int[]{4, 5, 6, 0, 0, 0};
        nums_2 = new int[]{1, 2, 3};
        solution.merge(nums_1, 3, nums_2, 3);
        assertArrayEquals(real, nums_1);
    }
}