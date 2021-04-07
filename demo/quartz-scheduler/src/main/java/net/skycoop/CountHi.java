package net.skycoop;

import org.quartz.*;

@PersistJobDataAfterExecution
public class CountHi implements Job {
    /**
     * JobDataMap 只有当前环境才有效，就算修改了也会被覆盖
     * 有个类的注解@DisallowConcurrentExecution，@PersistJobDataAfterExecution
     * 加了@PersistJobDataAfterExecution count就会被延续下去
     */
    @Override
    public void execute(JobExecutionContext context) throws JobExecutionException {
        JobKey key = context.getJobDetail().getKey();
        JobDataMap dataMap = context.getJobDetail().getJobDataMap();

        int count = dataMap.getInt("count");
        int raw_count = dataMap.getInt("raw_count");

        System.err.println("Instance " + key + " of Count: " + count + ", and raw_count is: " + raw_count);

        dataMap.put("count", ++count);
        System.err.println("after put dataMap --> Instance " + key + " of Count: " + dataMap.getInt("count"));
    }
}
