package net.skycoop.command;

import net.skycoop.Tool;
import net.skycoop.command.Command;

import java.util.Scanner;

public class UUIDCommand implements Command {

    @Override
    public void execute(Scanner in) {
        System.out.println(Tool.uuid());
    }

}
