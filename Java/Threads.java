// Two ways to create a thread

public class Threads {

    static class Method1 extends Thread {

        @Override
        public void run() {
            System.out.println("First way to create a thread");
        }
    }

    static class Method2 implements Runnable {

        public void run() {

            System.out.println("Thread running");

        }

    }

    public static void main(String[] args) {

        Method1 t1 = new Method1();

        t1.start();

        Thread t2 = new Thread(new Method2());

        t2.start();
    }

}

// ( output order may swap — threads run concurrently)
