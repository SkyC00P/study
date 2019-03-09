import java.util.Arrays;

public final class SortAlgorithm {

    private static final int[] data = new int[]{10, 50, 6, 1, 3, 5, 7, 44, 66, 22, 50, 60, 48, 151};
    private static final int[] soredData = new int[]{1, 3, 5, 6, 7, 10, 22, 44, 48, 50, 50, 60, 66, 151};

    /* 冒泡排序 */
    private static int[] BubbleSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);

        for (int i = 0; i < d.length; i++) {
            for (int j = i + 1; j < d.length; j++) {
                if (d[i] > d[j]) {
                    int k = d[i];
                    d[i] = d[j];
                    d[j] = k;
                }
            }
        }
        return d;
    }

    /* 简单选择排序 */
    private static int[] SelectSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);
        for (int i = 0; i < d.length; i++) {
            int min = i;
            for (int j = i + 1; j < d.length; j++) {
                if (d[j] < d[min]) {
                    min = j;
                }
            }
            if (min != i) {
                int tmp = d[i];
                d[i] = d[min];
                d[min] = tmp;
            }
        }
        return d;
    }

    /* 直接插入排序 */
    private static int[] InsertSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);
        for (int i = 1; i < d.length; i++) {
            if (d[i - 1] > d[i]) {
                int tmp = d[i];
                int j = i;
                while (j > 0 && d[j - 1] > tmp) {
                    d[j] = d[j - 1];
                    j--;
                }
                d[j] = tmp;
            }
        }
        return d;
    }

    /* 希尔排序 - 直接插入排序算法的改进版本*/
    private static int[] ShellSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);
        for (int step = d.length / 2; step > 0; step = step / 2) {
            // 对同组元素进行插入排序
            for (int i = step; i < d.length; i++) {
                int j = i;
                int temp = d[j];
                while (j - step >= 0 && temp < d[j - step]) {
                    d[j] = d[j - step];
                    j = j - step;
                }
                d[j] = temp;
            }
        }

        return d;
    }

    /* 堆排序 */
    private static int[] HeapSort(final int[] data){
        int[] d = Arrays.copyOf(data,data.length);

        return d;
    }

    public static void main(String[] args) {
        boolean bubble_result = Arrays.equals(soredData, BubbleSort(data));
        System.out.println("[BubbleSort]测试结果:" + bubble_result);

        boolean select_result = Arrays.equals(soredData, SelectSort(data));
        System.out.println("[SeclectSort]测试结果:" + select_result);

        boolean insert_result = Arrays.equals(soredData, InsertSort(data));
        System.out.println("[InsertSort]测试结果:" + insert_result);

        boolean shell_result = Arrays.equals(soredData, ShellSort(data));
        System.out.println("[ShellSort]测试结果:" + shell_result);

        boolean heap_result = Arrays.equals(soredData, HeapSort(data));
        System.out.println("[HeapSort]测试结果:" + heap_result);
    }
}


