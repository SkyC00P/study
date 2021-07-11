package done;

import java.util.*;

public class EmployeeImportance {
    class Employee {
        public int id;
        public int importance;
        public List<Integer> subordinates;
    }

    /**
     * Runtime: 6 ms, faster than 32.15% of Java online submissions for Employee Importance.
     * Memory Usage: 55.4 MB, less than 6.03% of Java online submissions for Employee Importance.
     */
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> map = new HashMap<>();
        Employee target = null;
        for (Employee employee : employees) {
            map.put(employee.id, employee);
            if (employee.id == id) target = employee;
        }
        int sum = 0;
        Queue<Employee> query = new ArrayDeque<>();
        query.add(target);

        while (!query.isEmpty()) {
            Employee em = query.remove();
            sum += em.importance;
            if (em.subordinates != null && !em.subordinates.isEmpty()) {
                for (int i : em.subordinates) {
                    query.add(map.get(i));
                }
            }
        }
        return sum;
    }
}
