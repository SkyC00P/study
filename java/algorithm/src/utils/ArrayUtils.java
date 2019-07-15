package utils;

import datastruct.TreeNode;

import java.util.ArrayList;
import java.util.List;

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
}