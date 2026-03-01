## Introduction

Multithreading = running multiple threads (lightweight processes) inside a single program at the same time.

A **thread** is the smallest unit of execution. Every Java program starts with one main thread.

If you have multiple CPUs(or cores), you can run multiple threads in parallel

---
## Lock

A **lock** is a mechanism that prevents multiple threads from accessing the same resource at the same time.

A **monitor lock** is the built-in lock every Java object has.

Every single object in Java = has one invisible lock attached to it.

---

## Why Multithreading Exists

- Better CPU utilization
    
- Faster performance for I/O-heavy tasks
    
- Parallel execution on multi-core CPUs
    
- Responsive UI (don’t freeze apps)
    

---

## Process vs Thread

| Process               | Thread                |
| --------------------- | --------------------- |
| Independent program   | Part of a process     |
| Own memory            | Shares memory         |
| Heavyweight           | Lightweight           |
| Slower context switch | Faster context switch |

---

## Creating Threads in Java

### 1. Extend `Thread` class

```java
class Gurt extends Thread {
    public void run() {
        System.out.println("Thread running");
    }
}

public class Main {
    public static void main(String[] args) {
        Gurt t1 = new MyThread();
        t1.start();  // start() creates new thread
    }
}
```

⚠️ Never call `run()` directly. Use `start()`.

---

### 2. Implement `Runnable` (Better Way)

```java
class Gurt implements Runnable {
    public void run() {
        System.out.println("Task running");
    }
}

public class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Gurt());
        t1.start();
    }
}
```

Why better?  
Java supports single inheritance. Implementing `Runnable` lets you extend another class.

---

## Thread Life Cycle

1. New
    
2. Runnable
    
3. Running
    
4. Blocked/Waiting
    
5. Terminated
    

---

## Important Thread Methods

- `start()` – starts thread
    
- `run()` – task code
    
- `sleep(ms)` – pause thread
    
- `join()` – wait for thread to finish
    
- `isAlive()` – check if running
    
- `setPriority()` – set thread priority
    
- `wait()` – releases the object's monitor and puts the current thread into **WAITING** state until another thread calls `notify()`/`notifyAll()`
    
- `notify()/notifyAll()` – wakes up one (`notify()`) or all (`notifyAll()`) threads that are waiting on the object's monitor

These are defined in `Thread.State`.

---

## Basic Example with Multiple Threads

```java
class Task implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Task());
        Thread t2 = new Thread(new Task());

        t1.start();
        t2.start();
    }
}
```

Output order is unpredictable. That’s normal. Threads run concurrently.

---

## Core Problems in Multithreading

- Race condition
    
- Deadlock
    
- Starvation
    
- Synchronization issues
    

These happen because threads share memory.

---

## Modern Way (Production Level)

Use Executor framework instead of manually creating threads.

```java
import java.util.concurrent.*;

public class Main {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(2);

        executor.submit(() -> {
            System.out.println("Task running");
        });

        executor.shutdown();
    }
}
```

---
## Java Synchronization Methods

### 1. `synchronized` (keyword)

Controls access to critical section.

**Method level:**

```java
synchronized void method() {
    // only one thread at a time
}
```

**Block level:**

```java
synchronized(this) {
    // critical section
}
```

Locks the object's monitor.
(The thread **grabs that object’s internal lock**, and no other thread can enter any `synchronized` code that uses that same object until the lock is released.)

---

### 2. `wait()`

- Releases the monitor lock
    
- Puts thread into **WAITING** state
    
- Must be inside `synchronized` block
    

---

### 3. `notify()`

- Wakes up one waiting thread
    
- Must be inside `synchronized` block
    

---

### 4. `notifyAll()`

- Wakes up all waiting threads
    
- Must be inside `synchronized` block
    

---

## Modern Synchronization
From `java.util.concurrent`:

### 5. `Lock` interface (ReentrantLock)

```java
Lock lock = new ReentrantLock();
lock.lock();
try {
    // critical section
} finally {
    lock.unlock();
}
```

More control than `synchronized`.

---

### 6. `ReadWriteLock`

Allows multiple readers, one writer.

---

### 7. `Semaphore`

Controls number of threads accessing a resource.

---

### 8. `CountDownLatch`, `CyclicBarrier`

Thread coordination tools.

---

## Bottom Line

Core synchronization =  
`synchronized`, `wait()`, `notify()`, `notifyAll()`

Serious real-world systems use `Lock` and `java.util.concurrent` utilities.