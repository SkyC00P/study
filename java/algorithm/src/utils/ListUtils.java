package utils;

import datastruct.ListNode;

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

    /**
     * 创建尾指针特意指向的链表
     * head = [3,2,0,-4], pos = 1
     *
     * @param nodes 链表的数组表示
     * @param pos   尾指针指向的结点，以0开始计算。-1表示null
     * @return
     */
    public static ListNode createList(int[] nodes, int pos) {
        if (nodes == null || nodes.length == 0) return null;
        ListNode node = new ListNode(nodes[0]);
        ListNode cur = node;
        for (int i = 1; i < nodes.length; i++) {
            cur.next = new ListNode(nodes[i]);
            cur = cur.next;
        }
        if (pos == -1 || pos >= nodes.length) cur.next = null;
        else {
            ListNode tail = node;
            for (int i = 0; i < pos; i++) {
                tail = tail.next;
            }
            cur.next = tail;
        }
        return node;
    }

    public static void print(ListNode node, int num) {
        if (node == null) {
            System.out.println("Null");
            return;
        }
        ListNode cur = node;
        for (int i = 0; i < num - 1; i++) {
            System.out.print(cur.val + "->");
            cur = cur.next;
        }
        System.out.println(cur == null ? "null" : cur.val);
    }
}
