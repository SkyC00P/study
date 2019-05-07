package threadpool;

import java.security.AccessController;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import java.util.Stack;
import java.util.concurrent.*;

public final class ThreadPool {

    private static class Data {
        int num = 5;

        void set(int num) {
            this.num = num;
        }

        int get() {
            return num;
        }
    }

    private static class addOne extends Thread {

        Data data;

        public addOne(Data data) {
            this.data = data;
        }

        @Override
        public void run() {
            System.out.println(+1);

            try {
                int n = data.get();
                Thread.sleep(3 * 1000);
                System.out.println(data.get());
                data.set(n + 1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private static class jianOne extends Thread {

        Data data;

        public jianOne(Data data) {
            this.data = data;
        }

        @Override
        public void run() {
            System.out.println(-1);

            int n = data.get();
            data.set(n - 1);
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Data d = new Data();
        addOne add = new addOne(d);
        jianOne jian = new jianOne(d);
        add.start();
        jian.start();
        add.join();
        jian.join();
        System.out.println(d.num);
    }

}


