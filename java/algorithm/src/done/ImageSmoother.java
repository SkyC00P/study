package done;

public class ImageSmoother {
    /**
     * Runtime: 6 ms, faster than 74.87% of Java online submissions for Image Smoother.
     * Memory Usage: 40 MB, less than 49.22% of Java online submissions for Image Smoother.
     */
    public int[][] imageSmoother(int[][] img) {
        int[][] arr = new int[img.length][img[0].length];
        for (int i = 0; i < img.length; i++) {
            int[] points = img[i];
            for (int j = 0; j < points.length; j++) {
                // (i-1,j-1) (i-1,j)  (i-1,j+1)
                // (i,j-1)   (i,j)    (i,j+1)
                // (i+1,j-1) (i+1,j)  (i+1,j+1)
                int sum = points[j];
                int count = 1;
                if (i - 1 >= 0) {
                    if (j - 1 >= 0) {
                        sum += img[i - 1][j - 1];
                        count++;
                    }
                    if (j + 1 < points.length) {
                        sum += img[i - 1][j + 1];
                        count++;
                    }
                    sum += img[i - 1][j];
                    count++;
                }

                if (j - 1 >= 0) {
                    sum += img[i][j - 1];
                    count++;
                }
                if (j + 1 < points.length) {
                    sum += img[i][j + 1];
                    count++;
                }

                if (i + 1 < img.length) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count++;
                    }
                    if (j + 1 < points.length) {
                        sum += img[i + 1][j + 1];
                        count++;
                    }
                    sum += img[i + 1][j];
                    count++;
                }
                arr[i][j] = sum / count;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        ImageSmoother main = new ImageSmoother();
        int[][] arr = new int[][]{{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
        int[][] smoother = main.imageSmoother(arr);
        for (int[] a : smoother) {
            for (int i : a) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
