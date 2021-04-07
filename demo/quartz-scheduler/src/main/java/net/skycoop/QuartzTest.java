package net.skycoop;


import org.quartz.JobDetail;
import org.quartz.Scheduler;
import org.quartz.SchedulerException;
import org.quartz.Trigger;
import org.quartz.impl.StdSchedulerFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Objects;
import java.util.Scanner;

import static org.quartz.JobBuilder.newJob;
import static org.quartz.SimpleScheduleBuilder.simpleSchedule;
import static org.quartz.TriggerBuilder.newTrigger;

/**
 * https://www.quartz-scheduler.org/documentation/quartz-2.3.0/tutorials/
 *
 * 关键的API
 * Scheduler - the main API for interacting with the scheduler.
 * Job - an interface to be implemented by components that you wish to have executed by the scheduler.
 * JobDetail - used to define instances of Jobs.
 * Trigger - a component that defines the schedule upon which a given Job will be executed.
 * JobBuilder - used to define/build JobDetail instances, which define instances of Jobs.
 * TriggerBuilder - used to define/build Trigger instances
 * <p>
 * ？一个任务只能有一个触发器，还是可以绑定多个？
 * ？DateBuilder 好像提供了一些有用的构建Date的方法
 * ？主要看 JobBuilder，TriggerBuilder，SimpleScheduleBulder
 * ？JobExecutionContext 能获得什么
 * ？JobDetail --> JobDataMap
 * ？Trigger 的实现有几个？常用的好像是SimpleTrigger ，CronTrigger
 * ？Jobs and Triggers好像都设置了identifying keys，具体有什么用？
 * ？如果job执行的时间超过下次调度的时间，那么会等待当前执行完成再执行吗
 */
public class QuartzTest {

    private static final Logger log = LoggerFactory.getLogger(QuartzTest.class);

    /**
     * 通用的调用逻辑
     * 1. 先获取Scheduler的工厂类来创建Scheduler。
     * 2. 让Scheduler启动
     * 3. 构建一个任务
     * 4. 构建一个触发器
     * 5. 将任务和触发器放到Scheduler里执行调度
     */
    public static void main(String[] args) throws SchedulerException {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String op = scanner.nextLine().trim();
            if (Objects.equals(op, "run")) {
                run();
            } else if (Objects.equals(op, "job_dtl")) {
                job_dtl();
            } else if (Objects.equals(op, "long task")) {
                long_task();
            } else {
                System.exit(0);
            }
        }
    }

    private static void long_task() throws SchedulerException {
        Scheduler scheduler = StdSchedulerFactory.getDefaultScheduler();
        scheduler.start();
        JobDetail job = newJob(LongTask.class)
                .withIdentity("job1", "long_task")
                .build();
        Trigger trigger = newTrigger()
                .withIdentity("trigger1", "long_task")
                .startNow()
                .withSchedule(simpleSchedule()
                        .withIntervalInSeconds(5)
                        .repeatForever())
                .build();
        scheduler.scheduleJob(job, trigger);
    }

    private static void job_dtl() throws SchedulerException {
        Scheduler scheduler = StdSchedulerFactory.getDefaultScheduler();
        scheduler.start();
        JobDetail job = newJob(CountHi.class)
                .withIdentity("job1", "job_dtl")
                .usingJobData("count", 0)
                .usingJobData("raw_count", 1)
                .build();
        Trigger trigger = newTrigger()
                .withIdentity("trigger1", "job_dtl")
                .startNow()
                .withSchedule(simpleSchedule()
                        .withIntervalInSeconds(5)
                        .repeatForever())
                .build();
        scheduler.scheduleJob(job, trigger);
    }

    private static void run() {
        log.info("----> start");
        try {
            // Grab the Scheduler instance from the Factory
            Scheduler scheduler = StdSchedulerFactory.getDefaultScheduler();

            // and start it off
            scheduler.start();
            // define the job and tie it to our HelloJob class
            JobDetail job = newJob(HelloJob.class)
                    .withIdentity("job1", "group1")
                    .build();

            // Trigger the job to run now, and then repeat every 40 seconds
            Trigger trigger = newTrigger()
                    .withIdentity("trigger1", "group1")
                    .startNow()
                    .withSchedule(simpleSchedule()
                            .withIntervalInSeconds(5)
                            .repeatForever())
                    .build();

            // Tell quartz to schedule the job using our trigger
            scheduler.scheduleJob(job, trigger);

        } catch (SchedulerException se) {
            se.printStackTrace();
        }
    }
}

