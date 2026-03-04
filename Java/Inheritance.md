
---

## 1. Definition

Inheritance is a mechanism where a **subclass (child)** acquires the properties and behaviors of a **superclass (parent)**. It enables **code reuse** and models **IS-A** relationships.

```java
class Animal {          // Superclass
    String name;
    void eat() { System.out.println(name + " eats"); }
}

class Dog extends Animal {   // Subclass
    void bark() { System.out.println("Woof!"); }
}
```

---

## 2. Types of Inheritance in Java

|Type|Supported?|How|
|---|---|---|
|Single|✅|`class B extends A`|
|Multilevel|✅|`A → B → C`|
|Hierarchical|✅|Multiple classes extend one parent|
|Multiple|❌ (classes)|Not allowed — diamond problem|
|Multiple|✅ (interfaces)|`class A implements I1, I2`|

```java
// Multilevel
class Animal { }
class Dog extends Animal { }
class Labrador extends Dog { }   // A → B → C

// Hierarchical
class Cat extends Animal { }
class Cow extends Animal { }
```

---

## 3. `super` Keyword

Used to access **parent class members** (constructor, method, field).

```java
class Animal {
    String name;
    Animal(String name) { this.name = name; }
    void sound() { System.out.println("Some sound"); }
}

class Dog extends Animal {
    String breed;

    Dog(String name, String breed) {
        super(name);          // calls Animal constructor — MUST be first line
        this.breed = breed;
    }

    @Override
    void sound() {
        super.sound();        // calls Animal's sound()
        System.out.println("Woof");
    }
}
```

---

## 4. Method Overriding

Subclass **redefines** a method with the same signature as the parent.

**Rules:**

- Same method name, return type, parameters
- Access modifier must be **same or wider** (not more restrictive)
- Cannot override `static`, `final`, or `private` methods
- `@Override` annotation is best practice

```java
class Shape {
    double area() { return 0; }
}

class Circle extends Shape {
    double radius;
    Circle(double r) { this.radius = r; }

    @Override
    double area() { return Math.PI * radius * radius; }
}
```

---

## 5. `final` and Inheritance

```java
final class A { }          // Cannot be extended
class B extends A { }      // ❌ Compile error

class C {
    final void show() { }  // Cannot be overridden
}
class D extends C {
    void show() { }        // ❌ Compile error
}
```

---

## 6. Constructor Chaining

Constructors are **not inherited**, but the parent constructor is **always called** (implicitly or explicitly via `super()`).

```java
class A {
    A() { System.out.println("A constructor"); }
}
class B extends A {
    B() {
        // super() called implicitly here if not written
        System.out.println("B constructor");
    }
}
// new B() → prints: "A constructor" then "B constructor"
```

---

## 7. Polymorphism via Inheritance (Runtime)

```java
Animal a = new Dog();   // Upcasting — Dog IS-A Animal
a.eat();                // Animal method (inherited)
// a.bark();            // ❌ Not accessible — reference type is Animal

// Downcasting
Dog d = (Dog) a;
d.bark();               // ✅ Now accessible
```

---

## 8. `instanceof` Operator

```java
Dog d = new Dog();
System.out.println(d instanceof Dog);     // true
System.out.println(d instanceof Animal);  // true (IS-A relationship)
```

---

## 9. Object Class — Root of All

Every class in Java implicitly extends `java.lang.Object`. Key inherited methods:

|Method|Purpose|
|---|---|
|`toString()`|String representation|
|`equals(Object o)`|Logical equality|
|`hashCode()`|Hash value|
|`getClass()`|Runtime class info|
|`clone()`|Shallow copy|

---

## 10. Key Points Summary

- Java supports **single inheritance** for classes; multiple via **interfaces**
- `super()` must be the **first statement** in subclass constructor
- Method overriding enables **runtime polymorphism**
- `static` methods are **hidden**, not overridden (no polymorphism)
- `private` members are **not inherited**
- Constructors are **not inherited**
- `final` class/method blocks inheritance/overriding

---

## Common Exam Trap: Method Hiding vs Overriding

```java
class A {
    static void display() { System.out.println("A"); }  // static
    void show() { System.out.println("A"); }             // instance
}
class B extends A {
    static void display() { System.out.println("B"); }  // HIDING, not overriding
    @Override
    void show() { System.out.println("B"); }             // TRUE overriding
}

A obj = new B();
obj.display();   // prints "A"  — resolved at compile time (method hiding)
obj.show();      // prints "B"  — resolved at runtime (polymorphism)
```

## Hiding

When a subclass defines a `static` method with the same signature as a `static` method in the parent, the subclass method **hides** the parent method — it doesn't override it.

**Why the difference matters:**

- **Overriding** → resolved at **runtime** based on the **object's actual type**
- **Hiding** → resolved at **compile time** based on the **reference type**

```java
class A {
    static void greet() { System.out.println("A"); }
}
class B extends A {
    static void greet() { System.out.println("B"); }  // hides A's greet()
}

A ref = new B();
ref.greet();   // prints "A"  ← reference type is A, resolved at compile time
B ref2 = new B();
ref2.greet();  // prints "B"  ← reference type is B
```

Static methods belong to the **class, not the object**, so the JVM doesn't do dynamic dispatch on them. The compiler just looks at the declared reference type and calls that class's version.

**One-liner:** Hiding = static method "overriding" that isn't actually polymorphic. The parent method isn't gone — it's just shadowed by the subclass version when called through a subclass reference.