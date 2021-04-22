package net.skycoop;

import org.quartz.Job;
import org.quartz.JobExecutionContext;
import org.quartz.JobExecutionException;

import java.util.Date;

public class ShowTimeJob implements Job {
    @Override
    public void execute(JobExecutionContext context) throws JobExecutionException {
        long id = System.currentTimeMillis();
        System.out.println(String.format("%d Run System time --> %tT", id, new Date()));
    }
}
