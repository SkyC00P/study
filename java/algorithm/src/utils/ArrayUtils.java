package utils;

import java.util.*;

public class ArrayUtils {

    public static boolean equalsIgnoreSore(int[] n1, int[] n2) {
        if (n1 == null && n2 == null) return true;
        if (n1 == null || n2 == null) return false;
        if (n1.length != n2.length) return false;

        List<Integer> list = new ArrayList<>();
        for (int i : n1) {
            list.add(i);
        }
        for (int i : n2) {
            list.remove(Integer.valueOf(i));
        }
        return list.isEmpty();
    }

    public static <T> boolean equalsFromIndex(T[] arr1, T[] arr2, int len) {
        if (arr1.length < len || arr2.length < len) {
            throw new IllegalArgumentException("len is less than one of array");
        }
        for (int i = 0; i < len; i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    public static boolean equalsFromIndex(char[] arr1, char[] arr2, int len) {
        if (arr1.length < len || arr2.length < len) {
            throw new IllegalArgumentException("len is less than one of array");
        }
        for (int i = 0; i < len; i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    public static boolean equals(int[] a, int[] b) {
        if (a == b) return true;
        if (a == null || b == null || a.length != b.length) return false;
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    static final int S_1 = 1;
    static final int S_2 = 2;
    static final int S_0 = 3;
    static int state = S_0;

    // [[],[27],[65,65],[19],[0],[18],[3],[42,0],[19],[42],[17,90],[31,76],[48,71],[5,50],[7,68],[73,74],[85,18],[74,95],[84,82],[59,29],[71,71],[42],[51,40],[33,76],[17],[89,95],[95],[30,31],[37,99],[51],[95,35],[65],[81],[61,46],[50,33],[59],[5],[75,89],[80,17],[35,94],[80],[19,68],[13,17],[70],[28,35],[99],[37],[13],[90,83],[41],[50],[29,98],[54,72],[6,8],[51,88],[13],[8,22],[85],[31,22],[60,9],[96],[6,35],[54],[15],[28],[51],[80,69],[58,92],[13,12],[91,56],[83,52],[8,48],[62],[54],[25],[36,4],[67,68],[83,36],[47,58],[82],[36],[30,85],[33,87],[42,18],[68,83],[50,53],[32,78],[48,90],[97,95],[13,8],[15,7],[5],[42],[20],[65],[57,9],[2,41],[6],[33],[16,44],[95,30]]
    public static int[][] toArray(String s) {
        Map<Integer, Stack<Integer>> map = new HashMap<>();
        Stack<Character> stack = new Stack<>();

        int index = 0;
        for (char ch : s.toCharArray()) {
            switch (ch) {
                case '[':
                    if (state == S_0) state = S_1;
                    if (state == S_1) state = S_2;
                    stack.push(ch);
                    break;
                case ']':
                    if (state == S_2) {
                        Stack<Integer> list = popList(stack);
                        map.put(index, list);
                        index++;
                        state = S_1;
                    }
                    break;
                case ',':
                    if (state == S_2) {
                        stack.push(ch);
                    }
                    break;
                default:
                    stack.push(ch);

            }
        }

        int[][] arr = new int[map.size()][];
        for (int i = 0; i < arr.length; i++) {
            Stack<Integer> list = map.get(i);
            int[] ar = new int[list.size()];
            int cur = 0;
            while (!list.isEmpty()) {
                ar[cur++] = list.pop();
            }
            arr[i] = ar;
        }
        return arr;
    }

    private static Stack<Integer> popList(Stack<Character> stack) {
        Stack<Integer> list = new Stack<>();
        StringBuilder num = new StringBuilder();
        while (!stack.isEmpty()) {
            Character ch = stack.pop();
            switch (ch) {
                case ',':
                    list.push(Integer.parseInt(num.toString()));
                    num = new StringBuilder();
                    break;
                case '[':
                    String s = num.toString();
                    if (s.length() != 0) {
                        list.push(Integer.parseInt(s));
                    }
                    return list;
                default:
                    num.insert(0, ch);
            }
        }
        return list;
    }
}
