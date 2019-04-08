import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumSubarrayTest {
    MaximumSubarray solution = new MaximumSubarray();
    int[] arr = new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    //[4,-1,2,1]
    @Test
    void maxSubArray() {
        assertEquals(6, solution.maxSubArray(arr));
    }

}