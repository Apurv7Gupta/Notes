## Java Strings — the real breakdown

### 1. What a `String` actually is

In Java, `String` is a class from `java.lang`. It’s:

- **Immutable** → once created, it can’t change.
    
- **Backed by a char array internally** (since Java 9, optimized with byte[] + encoding flag).
    
- **Stored in the String Pool** when created as a literal.
    

---

## 2. Creating Strings

### String literal (uses String Pool)

```java
String a = "hello";
String b = "hello";
```

Both `a` and `b` point to the same object in the pool.

### Using `new`

```java
String c = new String("hello");
```

This forces a new object in heap memory (separate from pool).

---

## 3. String Pool (important)

Java keeps a special memory area for string literals.

Why?

- Saves memory
    
- Faster comparisons when using `==` (reference compare)
    

Example:

```java
String a = "hi";
String b = "hi";
System.out.println(a == b); // true
```

But:

```java
String a = new String("hi");
String b = new String("hi");
System.out.println(a == b); // false
```

Use `.equals()` for content comparison:

```java
a.equals(b); // true
```

---
## 3a. Interning

```java
String s1 = new String("hello");
String s2 = s1.intern();
```

`intern()` forces string into pool (or returns existing one).

---

## 4. Immutability (big deal)

```java
String s = "hello";
s.concat(" world");
System.out.println(s);
```

Output:

```
hello
```

Why?  
Because `concat()` creates a **new object**, it doesn’t modify the original.

Correct:

```java
s = s.concat(" world");
```

Immutability gives:

- Thread safety
    
- Security
    
- Hashcode caching
    
- Safe use in collections
    

---

## 5. Common String Methods (Core Stuff)

### Length

```java
s.length();
```

### Character at index

```java
s.charAt(0);
```

### Substring

```java
s.substring(0, 3);
```

### Contains

```java
s.contains("ell");
```

### Equals

```java
s.equals("hello");
s.equalsIgnoreCase("HELLO");
```

### Compare lexicographically

```java
s.compareTo("world");
```

### Replace

```java
s.replace("l", "x");
```

### Split

```java
s.split(",");
```

### Trim

```java
s.trim();
```

---

## 6. `==` vs `.equals()` (classic mistake)

|Operator|What it checks|
|---|---|
|`==`|Memory reference|
|`.equals()`|Actual string content|

Always use `.equals()` unless you're intentionally checking reference identity.

---

## 7. String Concatenation

### Using `+`

```java
String s = "hello" + "world";
```

Compiler optimizes literals.

BUT in loops:

```java
String s = "";
for(int i=0; i<1000; i++){
    s += i; // BAD
}
```

This creates tons of objects.

---

## 8. Use `StringBuilder` for Performance

```java
StringBuilder sb = new StringBuilder();

for(int i=0; i<1000; i++){
    sb.append(i);
}

String result = sb.toString();
```

Why?

- Mutable
    
- No unnecessary object creation
    
- Way faster in loops
    

### `StringBuilder` vs `StringBuffer`

| Class         | Thread Safe | Faster |
| ------------- | ----------- | ------ |
| StringBuilder | ❌           | ✅      |
| StringBuffer  | ✅           | ❌      |

Use `StringBuilder` unless you truly need synchronization.

---

## 9. Important Edge Cases

### Strings are objects

```java
String s = null;
s.length(); // NullPointerException
```

### Empty vs null

```java
String s = "";
s.isEmpty(); // true
```

---

## 10. Memory Deep Dive

When you do:

```java
String s = "hello";
```

- Object created in heap
    
- Reference stored in stack
    
- Literal stored in String Pool
    

When you modify:

```java
s = "world";
```

- New object created
    
- Old object becomes eligible for GC (if no refs)
    

---

### 11. UTF-16 Encoding

Java uses UTF-16 internally. One char = 2 bytes (generally).

### 12. Escape sequences

```java
"\n"  // newline
"\t"  // tab
"\\"  // Backslash
"\""  // Double Quote
```

---

## 13.Converting Primitive to String 

#### 1. The Explicit Way: `String.valueOf()`

This is the "clean" and most readable way to convert any primitive to a String.



```java
int age = 25;
String s = String.valueOf(age); // "25"

boolean isJavaFun = true;
String s2 = String.valueOf(isJavaFun); // "true"
```

#### 2. The Implicit Way: Concatenation

If you use the `+` operator with a String and a primitive, Java automatically converts the primitive to a String for you.



```Java
int score = 100;
String message = "Your score is: " + score; 
// Internally, Java does something like: "Your score is: " + String.valueOf(score)
```

> **Note:** While convenient, using `+ ""` (e.g., `score + ""`) is generally considered slightly less efficient than `String.valueOf()` because it involves extra internal operations.

---

### B. Converting Strings back to Primitives (Parsing)

Section 13 implies the reverse is often needed, too. To get a number out of a String, you use **Wrapper Classes** (like `Integer`, `Double`, etc.).

|**Target Primitive**|**Parsing Method**|
|---|---|
|`int`|`Integer.parseInt("123")`|
|`double`|`Double.parseDouble("12.5")`|
|`boolean`|`Boolean.parseBoolean("true")`|

If the String isn't a valid number (e.g., `Integer.parseInt("abc")`), Java will throw a `NumberFormatException`.

---
