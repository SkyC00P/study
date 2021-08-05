package net.skycoop.command;

import java.util.Scanner;

public interface Command {

    void execute(Scanner in);

    default void print(Task task) {
        System.out.println(String.format("%s. %s --> %s", task.getId(), task.getName(), task.getDoc()));
    }
}
