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
    private static int[] HeapSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);
        int n = d.length;
        // 建立堆
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(d, n, i);

        // 一个个从堆顶取出元素
        for (int i = n - 1; i >= 0; i--) {
            int temp = d[0];
            d[0] = d[i];
            d[i] = temp;
            heapify(d, i, 0);
        }

        // System.out.println(Arrays.toString(d));
        return d;
    }

    /* 归并排序 */
    private static int[] MSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);
        mergeSort(d, 0, d.length - 1);
        return d;
    }

    /* 快速排序 */
    private static int[] QuickSort(final int[] data) {
        int[] d = Arrays.copyOf(data, data.length);
        quicksort(d, 0, d.length - 1);
        //System.out.println(Arrays.toString(d));
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

        boolean msort_result = Arrays.equals(soredData, MSort(data));
        System.out.println("[MSort]测试结果:" + msort_result);

        boolean q_result = Arrays.equals(soredData, QuickSort(data));
        System.out.println("[QuickSort]测试结果:" + q_result);
    }


    // ------------------------- 私有
    private static void heapify(int[] arr, int n, final int i) {

        int largest = i; // 将最大元素设置为堆顶元素
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // 如果 left 比 root 大的话
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // I如果 right 比 root 大的话
        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // 递归地定义子堆
            heapify(arr, n, largest);
        }

    }

    private static void mergeSort(int[] arr, int first, int last) {
        if (first == last) {
            return;
        }

        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid + 1, last);
    }

    private static void merge(int[] arr, int l, int m, int r) {
        int[] leftArray = new int[m - l];
        int[] rightArray = new int[r - m + 1];
        for (int i = l; i < m; i++) {
            leftArray[i - l] = arr[i];
        }
        for (int i = m; i <= r; i++) {
            rightArray[i - m] = arr[i];
        }

        int i = 0, j = 0;
        int k = l;

        while (i < leftArray.length && j < rightArray.length) {
            if (leftArray[i] < rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
                k++;
            } else {
                arr[k] = rightArray[j];
                j++;
                k++;
            }
        }

        while (i < leftArray.length) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < rightArray.length) {
            k++;
            j++;
        }
    }

    private static void quicksort(int[] arr, int left, int right) {
        if (arr == null || left < 0 || right < 0) {
            return;
        }
        if (left < right) {
            int dp = partition(arr, left, right);
            quicksort(arr, left, dp - 1);
            quicksort(arr, dp + 1, right);
        }
    }

    private static int partition(int arr[], int left, int right) {
        int pivot = arr[left];
        while (left < right) {
            while (left < right && arr[right] >= pivot) {
                right--;
            }

            if (left < right) {
                //System.out.println(String.format("1-left:%d,right:%d",left,right));
                arr[left] = arr[right];
                left++;
            }

            while (left < right && arr[left] <= pivot) {
                left++;
            }
            if (left < right) {
                //System.out.println(String.format("2-left:%d,right:%d",left,right));
                arr[right] = arr[left];
                right--;
            }
        }
        arr[left] = pivot;
        return left;
    }
}


