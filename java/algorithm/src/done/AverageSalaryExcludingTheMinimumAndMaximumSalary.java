package done;

import java.math.BigDecimal;
import java.util.Arrays;

public class AverageSalaryExcludingTheMinimumAndMaximumSalary {

/* 	Runtime: 1 ms, faster than 24.70% of Java online submissions for Average Salary Excluding the Minimum and Maximum Salary.
	Memory Usage: 37.5 MB, less than 13.89% of Java online submissions for Average Salary Excluding the Minimum and Maximum Salary. */
    public double average(int[] salary) {
        Arrays.sort(salary);
        int sum = 0;
        for (int i = 1; i < salary.length - 1; i++) {
            sum += salary[i];
        }
        BigDecimal b_sum = BigDecimal.valueOf(sum);
        BigDecimal b_avg = BigDecimal.valueOf(salary.length - 2);

        return b_sum.divide(b_avg, 5, BigDecimal.ROUND_HALF_UP).doubleValue();
    }

    public static void main(String[] args) {
        AverageSalaryExcludingTheMinimumAndMaximumSalary main = new AverageSalaryExcludingTheMinimumAndMaximumSalary();
        System.out.println(main.average(new int[] { 4000, 3000, 1000, 2000 }));
    }
}
