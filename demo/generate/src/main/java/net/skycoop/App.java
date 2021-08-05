package net.skycoop;

import net.skycoop.command.Task;

import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        System.out.println("支持以下命令:");
        print();
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String op = scanner.next().trim();
            Task task = Task.warp(op);
            if (task == null) {
                System.out.println("---> 查无此任务。");
                print();
            } else {
                task.run(scanner);
            }
        }
    }

    private static void print() {
        for (Task task : Task.values()) {
            task.print();
        }
    }
}
