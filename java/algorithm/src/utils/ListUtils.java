package utils;

import java.util.ArrayList;
import java.util.List;

public class ListUtils {
    public static List<List<Integer>> createList(String pattern) {
        String[] rows = pattern.split("\\|");
        List<List<Integer>> lists = new ArrayList<>();
        for (int i = 0; i < rows.length; i++) {
            List<Integer> list = new ArrayList<>();
            for (String s : rows[i].split(",")) {
                list.add(Integer.parseInt(s));
            }
            lists.add(list);
        }
        return lists;
    }

    public static void print(List<List<Integer>> list) {
        if (list == null || list.isEmpty()) {
            return;
        }

        for (int i = 0; i < list.size(); i++) {
            List<Integer> l = list.get(i);
            for (int j = 0; j < l.size(); j++) {
                System.out.print(l.get(j) + " ");
            }
            System.out.println();
        }
    }
}
