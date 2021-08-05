package done;

import java.util.ArrayList;
import java.util.List;

public class AddToArrayFormOfInteger {

    /**
     * Runtime: 4 ms, faster than 63.36% of Java online submissions for Add to Array-Form of Integer.
     * Memory Usage: 40.7 MB, less than 41.22% of Java online submissions for Add to Array-Form of Integer.
     */
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> k_list = new ArrayList<>();
        while (true) {
            int v = k / 10;
            int n = k % 10;
            k_list.add(0, n);
            if (v == 0) break;
            k = v;
        }
        List<Integer> list = new ArrayList<>();
        for (int n : num) {
            list.add(n);
        }
        if (k_list.size() <= list.size()) {
            return addToArrayForm(list, k_list);
        } else {
            return addToArrayForm(k_list, list);
        }

    }

    private List<Integer> addToArrayForm(List<Integer> list, List<Integer> k_list) {
        int index = list.size() - 1;
        boolean bit = false;
        for (int i = k_list.size() - 1; i >= 0; i--) {
            int n = k_list.get(i);
            int n1 = bit ? 1 : 0;
            int n2 = list.get(index) + n + n1;
            if (n2 >= 10) {
                list.set(index, n2 % 10);
                bit = true;
            } else {
                list.set(index, n2);
                bit = false;
            }
            index--;
        }
        while (bit && index >= 0) {
            int n3 = list.get(index) + 1;
            list.set(index, n3 == 10 ? 0 : n3);
            index--;
            bit = n3 == 10;
        }
        if (bit) list.add(0, 1);
        return list;
    }

    /**
     * 建立在k的位数小于num
     */
    public List<Integer> addToArrayForm_fail_1(int[] num, int k) {
        List<Integer> k_list = new ArrayList<>();
        while (true) {
            int v = k / 10;
            int n = k % 10;
            k_list.add(n);
            if (v == 0) break;
            k = v;
        }
        int index = num.length - 1;
        boolean bit = false;
        for (int n : k_list) {
            int n1 = bit ? 1 : 0;
            int n2 = num[index] + n + n1;
            if (n2 >= 10) {
                num[index] = n2 % 10;
                bit = true;
            } else {
                num[index] = n2;
                bit = false;
            }
            index--;
        }
        while (bit && index >= 0) {
            int n3 = num[index] + 1;
            num[index] = n3 == 10 ? 0 : n3;
            index--;
            bit = n3 == 10;
        }
        List<Integer> list = new ArrayList<>();
        for (int n : num) {
            list.add(n);
        }
        if (bit) list.add(0, 1);
        return list;
    }

    /**
     * 数溢出
     */
    public List<Integer> addToArrayForm_fail(int[] num, int k) {
        StringBuilder sb = new StringBuilder();
        for (int value : num) {
            sb.append(value);
        }
        long number = Long.parseLong(sb.toString()) + k;
        List<Integer> list = new ArrayList<>();
        while (true) {
            long v = number / 10;
            long n = number % 10;
            list.add(0, (int) n);
            if (v == 0) break;
            number = v;
        }
        return list;
    }

    /**
     * 浮点数溢出
     */
    public List<Integer> addToArrayForm_failed(int[] num, int k) {
        double sum = 0;
        for (int i = 0; i < num.length; i++) {
            sum += num[i] * Math.pow(10, num.length - i - 1);
        }
        int number = (int) (sum + k);
        List<Integer> list = new ArrayList<>();
        while (true) {
            int v = number / 10;
            int n = number % 10;
            list.add(0, n);
            if (v == 0) break;
            number = v;
        }
        return list;
    }

    public static void main(String[] args) {
        AddToArrayFormOfInteger main = new AddToArrayFormOfInteger();
        System.out.println(main.addToArrayForm(new int[]{1, 2, 0, 0}, 34));
        System.out.println(main.addToArrayForm(new int[]{9, 9, 9, 9, 9, 9, 9, 9, 9, 9}, 1));
        System.out.println(main.addToArrayForm(new int[]{0}, 23));
    }
}
