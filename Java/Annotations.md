An annotation is **metadata for your code**.

It’s extra info you attach to classes, methods, fields, etc.  
It does **not change the program logic by itself**.

It tells:

- The compiler
    
- The JVM
    
- Or frameworks
    

how to treat that code.

Java has **5 core annotation types**.

## 1. **Marker Annotations**

No elements. Just a flag.

Example:

```java
@Override
```

Custom:

```java
public @interface MyMarker {}
```

Usage:

```java
@MyMarker
class Test {}
```

Used when you just need presence/absence.

---

## 2. **Single-Value Annotations**

One element (commonly named `value`).

Example:

```java
@SuppressWarnings("unchecked")
```

Custom:

```java
public @interface Author {
    String value();
}
```

Usage:

```java
@Author("Rin")
class Code {}
```

If the element name is `value`, you don’t have to write `value=`.

---

## 3. **Full (Normal) Annotations**

Multiple elements.

Example:

```java
@Deprecated(since = "1.5", forRemoval = true)
```

Custom:

```java
public @interface Info {
    String author();
    int version();
}
```

Usage:

```java
@Info(author = "Rin", version = 2)
class App {}
```

Most flexible type.

---

## 4. **Meta-Annotations**

Annotations used on other annotations.

Important ones from `java.lang.annotation`:

- `@Target`
    
- `@Retention`
    
- `@Documented`
    
- `@Inherited`
    
- `@Repeatable`
    

Example:

```java
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
public @interface Log {}
```

These control where and how annotations behave.

---

## 5. **Repeatable Annotations**

Allows same annotation multiple times.

Example:

```java
@Repeatable(Roles.class)
public @interface Role {
    String value();
}
```

Container:

```java
public @interface Roles {
    Role[] value();
}
```

Usage:

```java
@Role("ADMIN")
@Role("USER")
class Account {}
```

---

### Also Know (Interview Bait)

Annotation elements can only be:

- Primitive types
    
- String
    
- Class
    
- Enum
    
- Annotation
    
- Array of above
    

No objects. No generics. No null.