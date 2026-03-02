
In Java, **packages** are just namespaces. They organize classes, prevent name collisions, and control access.

## Why they exist

- Avoid class name conflicts (`List` in `java.util` vs `List` somewhere else)
    
- Group related code
    
- Control visibility (`protected`, package-private)
    

---

## Built-in packages (core ones)

- `java.lang` → auto-imported (`String`, `Math`, `System`)
    
- `java.util` → collections (`List`, `Map`, `HashMap`)
    
- `java.io` → file handling
    
- `java.nio` → modern I/O
    
- `java.time` → date/time (use this, not old `Date`)
    
- `java.net` → networking
    
- `java.sql` → database
    
- `java.awt`, `javax.swing` → GUI (legacy but still around)
    

---

## Importing

```java
import java.util.List;          // specific import
import java.util.*;             // wildcard (not recommended in large projects)
```

Or use fully qualified name:

```java
java.util.List<String> list;
```

---

## Access levels across packages

| Modifier      | Same Class | Same Package | Subclass | Other Package       |
| ------------- | ---------- | ------------ | -------- | ------------------- |
| `public`      | ✅          | ✅            | ✅        | ✅                   |
| `protected`   | ✅          | ✅            | ✅        | ❌ (unless subclass) |
| (no modifier) | ✅          | ✅            | ❌        | ❌                   |
| `private`     | ✅          | ❌            | ❌        | ❌                   |

Default (no modifier) = **package-private**.

---

## Naming convention

- All lowercase
    
- Reverse domain style (industry standard)
    

Example:

```
com.google.gson
org.springframework.boot
io.github.username.project
```

This avoids conflicts globally.

---

That’s it. Packages = clean structure + name safety + access control.



---
## User-Defined Packages in Java

A package you create yourself.

## 1️⃣ Creating a Package

Folder structure must match package name.

```java
package com.blud.project.utils;  // must be first line

public class Gurt {
    public static void sayHi() {
        System.out.println("Hi");
    }
}
```

Directory:

```
com/blud/project/utils/Gurt.java
```

If structure doesn’t match → compiler error.

---

## 2️⃣ Compiling

From `com` directory:

```bash
javac blud/utils/Gurt.java
```

---

## 3️⃣ Using the Package (Importing)

In another class:

```java
import com.blud.utils.Gurt;

public class Main {
    public static void main(String[] args) {
        System.out.println(Gurt.add(2, 3));
    }
}
```

Or wildcard (not ideal in large projects):

```java
import com.blud.utils.*;
```

---

## 4️⃣ Running

```bash
java Main
```

If running with package:

```bash
java com.blud.utils.Gurt
```

Now you **cannot** run it like this:

```bash
java Gurt   ❌
```
You must use the **fully qualified class name**:

```bash
java com.blud.utils.Gurt
```

## Important rule

You can only run a class if it has:

```bash
public static void main(String[] args)
```

No `main()` = nothing to execute.

---

## Bottom Line

User-defined package =

- `package` keyword
    
- Matching folder structure
    
- `import` to use it
    
- Clean modular organization
    

That’s it.