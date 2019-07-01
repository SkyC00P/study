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
}