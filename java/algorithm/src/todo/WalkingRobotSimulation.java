package todo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 874
 */
public class WalkingRobotSimulation {
    int N = 1, E = 2, S = 3, W = 4;
    Map<Integer, List<Integer>> x_map = new HashMap<>();
    Map<Integer, List<Integer>> y_map = new HashMap<>();

    class Robot {
        int x = 0, y = 0, direction = 1;
    }

    public int robotSim(int[] commands, int[][] obstacles) {

        for (int[] point : obstacles) {
            List<Integer> x_list = x_map.getOrDefault(point[0], new ArrayList<>());
            x_list.add(point[1]);
            x_list.sort(Integer::compareTo);
            x_map.put(point[0], x_list);

            List<Integer> y_list = y_map.getOrDefault(point[1], new ArrayList<>());
            y_list.add(point[0]);
            y_list.sort(Integer::compareTo);
            y_map.put(point[1], y_list);
        }

        Robot robot = new Robot();
        // direction 1 北 2 东 3 南 4 西
        for (int c : commands) {
            switch (c) {
                // 左转
                case -1:
                    if (robot.direction == N) robot.direction = W;
                    else robot.direction = robot.direction - 1;
                    break;
                // 右转
                case -2:
                    if (robot.direction == W) robot.direction = N;
                    else robot.direction = robot.direction + 1;
                    break;
                default:
                    walk(c, robot, obstacles);
            }
        }

        return robot.x * robot.x + robot.y * robot.y;
    }

    private void walk(int c, Robot robot, int[][] obstacles) {
        if (robot.direction == N) {
            List<Integer> y_list = x_map.get(robot.x);
            int _y = robot.y;
            robot.y = robot.y + c;
            int min = Integer.MAX_VALUE;
            int[] p;
            for (int[] point : obstacles) {
                if (point[0] == robot.x && point[1] > _y) {
                    min = Math.min(min, _y - point[1]);
                }
            }
        }
    }
}
