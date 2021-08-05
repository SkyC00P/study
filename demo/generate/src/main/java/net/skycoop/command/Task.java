package net.skycoop.command;

import net.skycoop.Tool;

import java.util.Objects;
import java.util.Scanner;

public enum Task {

    Exit("0", "exit", "退出", in -> { System.exit(0); }),
    UUID("1", "uuid", "打印一个随机的UUID", new UUIDCommand());

    private String id;
    private String name;
    private String doc;
    private Command command;

    Task(String id, String name, String doc, Command command) {
        this.id = id;
        this.name = name;
        this.command = command;
        this.doc = doc;
    }

    public static Task warp(String op) {
        if (Tool.isBlank(op)) return null;
        for (Task task : Task.values()) {
            if (Objects.equals(op, task.id) || Objects.equals(op, task.name)) {
                return task;
            }
        }
        return null;
    }

    public void run(Scanner scanner) {
        command.execute(scanner);
    }

    public void print() {
        command.print(this);
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getDoc() {
        return doc;
    }
}
