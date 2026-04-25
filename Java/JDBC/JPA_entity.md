An **entity** in JPA/Hibernate is just a Java class that represents a table in the database.

Example database table:

```text
students
----------------
id      name
1       Rin
2       Alice
```

Equivalent entity:

```java
import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Student {

    @Id
    private int id;

    private String name;

    // getters and setters
}
```

What this means:

- `Student` class ↔ `students` table
    
- object fields ↔ table columns
    
- one object ↔ one row
    

Example object:

```java
Student s = new Student();

s.setId(1);
s.setName("Rin");
```

Hibernate/JPA converts that into database data automatically.

`@Entity`  
= marks the class as database-mapped.

`@Id`  
= primary key.

Basically:

> Entity = Java object version of a database table.


---
“getters and setters” are just methods used to read or change private variables in a class.

Example:

```java
public class Student {

    private int id;
    private String name;

    // getter
    public int getId() {
        return id;
    }

    // setter
    public void setId(int id) {
        this.id = id;
    }

    // getter
    public String getName() {
        return name;
    }

    // setter
    public void setName(String name) {
        this.name = name;
    }
}
```

Usage:

```java
Student s = new Student();

s.setId(1);          // set value
s.setName("Rin");

System.out.println(s.getName()); // get value
```

Why they exist:  
Because fields are usually `private`.

Without setters/getters:

```java
s.name = "Rin"; // ERROR if private
```

So methods control access to the data.

This is basic **encapsulation** in OOP.

---
### A few super common annotations:

```java

@Entity
@Table(name = "students")
public class Student {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "student_name")
    private String name;
}

```

- `@GeneratedValue` → auto-increment IDs

`auto-increment IDs` means the database automatically generates the ID for each new row.

Without auto-increment:

```sql
INSERT INTO students VALUES(1, 'Rin');
INSERT INTO students VALUES(2, 'Alice');
```

You manually manage IDs. Annoying and error-prone.

With auto-increment:

```sql
INSERT INTO students(name) VALUES('Rin');
INSERT INTO students(name) VALUES('Alice');
```

Database automatically does:

```text
1 Rin
2 Alice
```

In JPA:

```java
@Id
@GeneratedValue(strategy = GenerationType.IDENTITY)
private int id;
```

Meaning:

- `@Id` → primary key
    
- `@GeneratedValue` → auto-generate it
    
- `IDENTITY` → let the database handle incrementing
    

Then:

```java
Student s = new Student();

s.setName("Rin");

entityManager.persist(s);
```

No need:

```java
s.setId(...)
```

Database handles it automatically.


And this matters too:

```java

public Student() {  
}

```

JPA requires a no-argument constructor.
