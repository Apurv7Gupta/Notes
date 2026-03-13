A **static class in Java** is a class declared with the `static` keyword **inside another class**. It belongs to the outer class rather than to an instance of that class.

Java **does not allow top-level classes to be static**. Only **nested classes** can be declared static.

Such a class is called a **Static Nested Class**.

---

### 2. Syntax

```java
class OuterClass {

    static class NestedClass {
        void display() {
            System.out.println("Inside static nested class");
        }
    }

}
```

---

### 3. Creating an Object

A static nested class **does not require an object of the outer class**.

```java
class Main {
    public static void main(String[] args) {

        OuterClass.NestedClass obj =
            new OuterClass.NestedClass();

        obj.display();
    }
}
```

Output:

```
Inside static nested class
```

---

### 4. Characteristics of Static Class

1. Declared using the **`static` keyword**.
    
2. Must be **inside another class**.
    
3. Cannot access **non-static members of the outer class directly**.
    
4. Can access **static members of the outer class directly**.
    
5. Does **not require an outer class object** to be instantiated.
    
6. Used for **logical grouping of classes** that are only used inside one outer class.
    

---

### 5. Example Program

```java
class Outer {

    static int x = 10;   // static variable

    static class Inner {

        void show() {
            System.out.println("Value of x = " + x);
        }

    }

}

public class Test {

    public static void main(String[] args) {

        Outer.Inner obj = new Outer.Inner();
        obj.show();

    }

}
```

Output:

```
Value of x = 10
```

Explanation:  
The static nested class `Inner` can directly access the static variable `x` of the outer class.

---

### 6. Advantages

- Improves **code organization**.
    
- Provides **better encapsulation**.
    
- Reduces **memory usage** because it doesn't require an outer class object.
    
- Useful when the nested class **only needs access to static members**.
    

---

### 7. Difference: Static Nested Class vs Inner Class

| Feature                 | Static Nested Class | Inner Class         |
| ----------------------- | ------------------- | ------------------- |
| Requires outer object   | No                  | Yes                 |
| Access to outer members | Only static members | Static + non-static |
| Memory usage            | Lower               | Higher              |


---

### 8. Conclusion

A **static nested class** in Java is a class declared inside another class using the `static` keyword. It behaves like a normal class but is logically grouped inside the outer class and can be accessed without creating an object of the outer class.

---

## Static Members (Fields & Methods)


```java
public class Counting {
    private static int count = 0; // static field shared across ALL instances

    public Counter() {
        count++;
    }

    public static int getCount() { // static method — called on class, not object
        return count;
    }

    public static void main(String[] args) {
        new Counting();
        new Counting();
        new Counting();
        System.out.println(Counting.getCount()); // Output: 3
    }
}
```

### Rules for static methods:

- Can **only** directly access static members
- Cannot use `this` or `super`
- Called via `ClassName.method()` (not on instance)

---
### Static Block (Static Initializer)

Runs **once** when the class is loaded into memory, before any object is created:

```java
public class Config {
    static final String DB_URL;

    static {
        // Runs once at class loading
        DB_URL = "jdbc:mysql://localhost:3306/mydb";
        System.out.println("Static block executed");
    }
}
```

---

### Static Import

Allows using static members without class prefix:

```java
import static java.lang.Math.PI;
import static java.lang.Math.sqrt;

public class Circle {
    double area(double r) {
        return PI * r * r; // instead of Math.PI
    }
}
```

---
### Common Exam Points / Pitfalls

1. **Static method cannot call non-static method directly** — compile error.
2. **`main()` is static** because JVM calls it without creating an object.
3. **Static nested class ≠ inner class** — inner class requires outer instance; static nested class does not.
4. **Static variables are shared** — changing in one object affects all.
5. **Overriding static methods is NOT polymorphism** — it's method hiding.

```java
class Animal {
    static void sound() { System.out.println("Animal"); }
}
class Dog extends Animal {
    static void sound() { System.out.println("Dog"); } // hides, not overrides
}
// Animal a = new Dog(); a.sound(); → prints "Animal" (resolved at compile time)
```
