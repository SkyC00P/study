package net.skycoop;

import org.quartz.Job;
import org.quartz.JobExecutionContext;
import org.quartz.JobExecutionException;

import java.util.Date;

public class LongTask implements Job {
    @Override
    public void execute(JobExecutionContext context) throws JobExecutionException {
        long id = System.currentTimeMillis();
        System.out.println(String.format("%d Run System time --> %tT", id, new Date()));
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(String.format("%d After Run System time --> %tT", id, new Date()));
    }
}
