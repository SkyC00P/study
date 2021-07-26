package done;

import java.util.Stack;

public class FlippingAnImage {
    /**
     * Runtime: 1 ms, faster than 29.59% of Java online submissions for Flipping an Image.
     * Memory Usage: 39.4 MB, less than 41.59% of Java online submissions for Flipping an Image.
     */
    public int[][] flipAndInvertImage(int[][] image) {
        for (int i = 0; i < image.length; i++) {
            flip(image[i]);
            invert(image[i]);
        }
        return image;
    }

    private void invert(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (~arr[i]) & 1;
        }
    }

    private void flip(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        for (int n : arr) {
            stack.push(n);
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = stack.pop();
        }
    }

}
