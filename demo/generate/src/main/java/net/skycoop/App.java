package net.skycoop;

import java.util.Objects;
import java.util.Scanner;

/**
 * Hello world!
 */
public class App {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            String op = scanner.next().trim();
            if (Objects.equals(op, "uuid")) {
                System.out.println(Tool.uuid());
            }
        }
    }
}
