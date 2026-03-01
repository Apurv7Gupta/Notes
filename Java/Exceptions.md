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