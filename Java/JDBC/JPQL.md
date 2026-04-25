**JPQL (Java Persistence Query Language)** is a query language used in **JPA** to interact with database data using **Java objects/entities**, not table names directly.

Think of it like:

- SQL → works with tables/columns
    
- JPQL → works with Java classes/fields
    

Example entity:

```java
@Entity
public class Student {

    @Id
    private int id;

    private String name;
}
```

SQL version:

```sql
SELECT * FROM students;
```

JPQL version:

```java
SELECT s FROM Student s
```

Notice:

- `Student` = Java class name
    
- `s.name` = Java field name
    
- not database column names
    

Example:

```java
Query q = entityManager.createQuery(
    "SELECT s FROM Student s WHERE s.id = 1"
);

List<Student> list = q.getResultList();
```

CRUD with JPQL:

### INSERT

JPQL does **not** support normal INSERT statements.

Use:

```java
entityManager.persist(student);
```

### READ

```java
SELECT s FROM Student s
```

### UPDATE

```java
UPDATE Student s SET s.name='Rin' WHERE s.id=1
```

### DELETE

```java
DELETE FROM Student s WHERE s.id=1
```

Main advantages:

- database independent
    
- object-oriented
    
- cleaner with Hibernate/JPA
    
- avoids raw SQL everywhere
    

Usually used with Hibernate and Spring Boot.
