package done;

public class RectangleOverlap {

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Rectangle Overlap.
     * Memory Usage: 36.3 MB, less than 47.39% of Java online submissions for Rectangle Overlap.
     */
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
}
