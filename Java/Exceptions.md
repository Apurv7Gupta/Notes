## 1. What Are Java Exceptions?

An **exception** is an object that represents a runtime error. When something goes wrong, Java creates an exception object and “throws” it.

All exceptions inherit from:

- `Throwable`
    
    - `Error` → JVM-level problems (OutOfMemoryError). Don’t handle these.
        
    - `Exception`
        
        - **Checked exceptions** (must be handled or declared)
            
        - **Unchecked exceptions** (`RuntimeException` and its subclasses)
            

### Checked vs Unchecked

**Checked (compile-time enforced):**

- `IOException`
    
- `SQLException`  
    You must handle or declare them.
    

**Unchecked (runtime):**

- `NullPointerException`
    
- `ArrayIndexOutOfBoundsException`
    
- `IllegalArgumentException`  
    No compile-time enforcement.
    

---

## 2. Java Exception Handling

Java uses:

```java
try {/* risky code*/}
catch (ExceptionType e) {/* handle*/}
finally {/* always runs */}
```

### Example

```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("You can't divide by zero.");
} finally {
    System.out.println("Done.");
}
```

Flow:

- Exception occurs
    
- Matching `catch` runs
    
- `finally` always runs (even if exception happens)
    
## 3. throw (Manually Throwing Exceptions)

Use `throw` when you want to explicitly trigger an exception.

```java
public void setAge(int age) {
    if (age < 0) {
        throw new IllegalArgumentException("Age cannot be negative");
    }
}
```

You can throw:

- Built-in exceptions
    
- Custom exceptions
    

---

## 4. throws (Declaring Exceptions)

`throws` is used in method signatures to declare checked exceptions.

```java
public void readFile(String path) throws IOException {
    Files.readAllLines(Path.of(path));
}
```

Meaning:

- “I’m not handling this here. Caller must deal with it.”
    

If you don’t catch a checked exception, you must declare it.

---

## 5. Catching Multiple Exceptions

### Option 1: Multiple catch blocks

```java
try {
    risky();
} catch (IOException e) {
    System.out.println("IO issue");
} catch (SQLException e) {
    System.out.println("DB issue");
}
```

---

### Option 2: Multi-catch (Java 7+)

Cleaner:

```java
try {
    risky();
} catch (IOException | SQLException e) {
    System.out.println("Something failed: " + e.getMessage());
}
```

Rules:

- Exceptions must not be in parent-child relationship.
    
- `e` is implicitly final.
    

---

## 6. Try-With-Resources


When you open stuff like:

- `FileInputStream`
    
- `BufferedReader`
    
- `Connection`
    
- `Socket`
    

You **must close it** or you leak memory/file handles.

Try-With-Resources auto-closes anything that implements `AutoCloseable`.

```java
try (FileInputStream fis = new FileInputStream("file.txt")) {
    // use fis
} catch (IOException e) {
    e.printStackTrace();
}
```

When the `try` block finishes (even if it crashes), Java **automatically calls `fis.close()`**.

No `finally`. No manual close needed. No leaks.

---

## 7. Custom Exception (Important)

```java
public class InvalidUserException extends Exception {
    public InvalidUserException(String message) {
        super(message);
    }
}
```

Use:

```java
if (!isValid(user)) {
    throw new InvalidUserException("User invalid");
}
```

---


### Exception Hierarchy in Java

```
Throwable
 ├── Error
 └── Exception
      ├── IOException
      ├── RuntimeException
      │    ├── ArithmeticException
      │    ├── NullPointerException
      │    └── ArrayIndexOutOfBoundsException
      └── Other Checked Exceptions
```


### Java throw & throws

### **1. throw**

- **Purpose:** Used to **explicitly throw a single exception** from a method or block.
    
- **Type:** Follows by an **instance of Exception**.
    
- **Used inside:** Method body.
    
- **Example:**
    

```java
public class ThrowDemo {
    static void checkAge(int age) {
        if (age < 18) {
            throw new ArithmeticException("Not allowed to vote"); // throwing exception
        } else {
            System.out.println("Eligible to vote");
        }
    }

    public static void main(String[] args) {
        checkAge(15);
    }
}
```

**Output:**

```
Exception in thread "main" java.lang.ArithmeticException: Not allowed to vote
```


If a method has `throws IOException`, the **caller of the method must handle it**, either with a try-catch or by propagating it further with its own `throws`.

---

### **2. throws**

- **Purpose:** Used in method declaration to **declare the exceptions a method might throw**.
    
- **Type:** Can declare **multiple exceptions**, separated by commas.
    
- **Used in:** Method signature.
    
- **Example:**
    

```java
import java.io.*;

public class ClassName {
    static void readFile() throws IOException {
        FileReader fr = new FileReader("test.txt"); // might throw IOException
    }

    public static void main(String[] args) {
        try {
            readFile();
        } catch (IOException e) {
            System.out.println("File not found: " + e);
        }
    }
}
```

---

### **Key Differences**

| Feature             | `throw`                          | `throws`                                 |
| ------------------- | -------------------------------- | ---------------------------------------- |
| **Usage**           | To throw an exception            | To declare exceptions a method may throw |
| **Where**           | Inside method/block              | In method signature                      |
| **Multiple?**       | Only **one** exception at a time | Can declare **multiple** exceptions      |
| **Object vs Class** | Requires an **exception object** | Uses **exception class name(s)**         |

---

Bottom line: `throw` = “I’m throwing this exception now.”  
`throws` = “This method **might throw** these exceptions, handle it outside.”


### Java catch Multiple Exceptions

### **Catching Multiple Exceptions**

In Java, you can catch **more than one exception** in two main ways:

---

### **1. Multi-Catch Block (Java 7+)**

- You can catch **different exceptions in a single `catch`** using `|`.
    
- **Syntax:**
    

```java
try {  
    int a = 10 / 0;           // ArithmeticException  
    String s = null;  
    System.out.println(s.length()); // NullPointerException  
} catch (ArithmeticException | NullPointerException e) {  
    System.out.println("Exception caught: " + e);  
}
```
- The variable `e` is **effectively final**.
    
- Cleaner than writing multiple catch blocks for related handling.
    

---

### **2. Multiple `catch` Blocks**

- You can also handle **each exception differently** with separate `catch` blocks:
    

```java
try {  
    int a = 10 / 0;             
    String s = null;  
    System.out.println(s.length());  
}   
catch (ArithmeticException e) {  
    System.out.println("Divide by zero error: " + e);  
}   
catch (NullPointerException e) {  
    System.out.println("Null pointer error: " + e);  
}   
catch (Exception e) {  // generic catch-all  
    System.out.println("Other exception: " + e);  
}
```

- Order matters: **catch subclasses first, superclass later** (`Exception` last). Otherwise, compiler error.
    

---

### **Rules & Notes**

1. Multi-catch is **Java 7+ only**.
    
2. In multi-catch, **you cannot reassign the exception variable**.
    
3. Using multiple catch blocks allows **different handling** for different exceptions.
    
4. Catching `Exception` alone is **not recommended**, but works as a last-resort.

---
