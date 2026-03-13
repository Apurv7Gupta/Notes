Recursion is a programming technique where a method calls itself to solve a problem. A recursive method breaks a large problem into smaller subproblems of the same type until it reaches a **base case**, which stops the recursion.

A recursive function has **two essential parts**:

1. **Base Case** – the condition where recursion stops.
    
2. **Recursive Case** – the part where the function calls itself with a smaller input.
    

---

### How Recursion Works (Call Stack)

Each recursive call creates a new **stack frame** on the JVM call stack. When the base case is reached, frames unwind (return values propagate back).


### Structure of a Recursive Method in Java

```java
returnType methodName(parameters) {
    if (baseCondition) {
        return value;   // Base case
    } else {
        return methodName(modifiedParameters); // Recursive call
    }
}
```

---

### Example: 

1)Factorial Using Recursion

The factorial of a number **n** is calculated as:

$n! = n \times (n-1)!$

and

$0! = 1$

**Java Program:**

```java
class FactorialRecursion {

    static int factorial(int n) {
        if (n == 0 || n == 1) {  // Base case
            return 1;
        }
        return n * factorial(n - 1);  // Recursive call
    }

    public static void main(String[] args) {
        System.out.println("Factorial: " + factorial(5));
    }
}
```

**Output**

```
Factorial: 120
```

**Working:**  
factorial(5) → 5 × factorial(4)  
factorial(4) → 4 × factorial(3)  
factorial(3) → 3 × factorial(2)  
factorial(2) → 2 × factorial(1)  
factorial(1) → 1 (base case)

Then results return back up the call stack.


2)Fibonacci — `F(n) = F(n-1) + F(n-2)`


```java
public static int fibonacci(int n) {
    if (n <= 1) return n;           // Base cases: F(0)=0, F(1)=1
    return fibonacci(n - 1) + fibonacci(n - 2); // Tree recursion
}
```

---

### Types of Recursion


Main Types:

1. **Direct Recursion**  
    A function directly calls itself.
    
2. **Indirect Recursion**  
    A function calls another function which eventually calls the first function.
    

Example:

```
A() → B()
B() → A()
```

More Types:

| **Type**        | **Description**                        | **Example**               |
| --------------- | -------------------------------------- | ------------------------- |
| **Direct**      | Method calls itself                    | `f() → f()`               |
| **Indirect**    | A calls B, B calls A                   | `f() → g() → f()`         |
| **Tail**        | Recursive call is the last operation   | Optimizable by compiler   |
| **Non-tail**    | Work done after recursive call returns | Factorial                 |
| **Linear**      | Single recursive call per invocation   | Factorial, Power          |
| **Tree/Binary** | Two recursive calls per invocation     | Fibonacci, Tree traversal |

---

### Advantages of Recursion

- Makes code **shorter and cleaner**.
    
- Useful for problems involving **trees, graphs, and divide-and-conquer algorithms**.
    
- Simplifies complex problems by breaking them into smaller ones.
    

---

### Disadvantages of Recursion

- Uses **more memory** due to function call stack.
    
- Can cause **StackOverflowError** if base condition is missing.
    
- Sometimes **slower than iteration**.
    

---

### Applications of Recursion

- Factorial calculation
    
- Fibonacci series
    
- Tree and graph traversal
    
- Divide and conquer algorithms (Merge Sort, Quick Sort)
    
- Backtracking problems
    


### Recursion vs Iteration

|Aspect|Recursion|Iteration|
|---|---|---|
|Readability|Often cleaner for tree/divide problems|Better for simple loops|
|Space|O(n) stack frames (risk: StackOverflow)|O(1) typically|
|Speed|Slight overhead (method call stack)|Faster in practice|
|Debugging|Harder to trace|Easier|
|Use case|Trees, graphs, divide & conquer|Linear traversal|


---

**Conclusion:**  
Recursion in Java is a powerful technique where a method repeatedly calls itself until a base condition is satisfied. It is widely used for solving problems that can be broken into smaller similar subproblems.
