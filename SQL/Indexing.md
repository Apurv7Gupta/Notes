**Indexing** is a database technique that speeds up data retrieval by creating a separate data structure that points to the location of rows, similar to how a book's index helps you find a topic without reading every page.

### Without an Index

Suppose you have a table:

| ID | Name    | Age |
| -- | ------- | --- |
| 1  | Alice   | 22  |
| 2  | Bob     | 25  |
| 3  | Charlie | 20  |

Query:

```sql
SELECT * FROM users WHERE Name = 'Bob';
```

Without an index, the database performs a **full table scan**:

* Check Alice ❌
* Check Bob ✅
* Stop

For a table with millions of rows, this is slow.

---

### With an Index

If you create an index:

```sql
CREATE INDEX idx_name ON users(Name);
```

The database builds a structure (typically a **B-tree**) like:

```
Alice   → Row 1
Bob     → Row 2
Charlie → Row 3
```

Now it can quickly find **Bob** without scanning every row.

---

### Why Use Indexing?

* Faster `SELECT` queries
* Faster searches using `WHERE`
* Faster `JOIN` operations
* Faster sorting (`ORDER BY`)
* Faster grouping (`GROUP BY`)

---

### Disadvantages

Indexes are not free:

* Consume extra disk space.
* Slow down `INSERT`, `UPDATE`, and `DELETE` because the index must also be updated.

---

### Example

Without index:

```sql
SELECT * FROM employees
WHERE employee_id = 5000;
```

The database may scan every row.

With index:

```sql
CREATE INDEX idx_empid
ON employees(employee_id);
```

The database jumps directly to employee **5000**, making the query much faster.

### Analogy

Think of a textbook:

* **Without an index:** You flip through every page to find "Photosynthesis."
* **With an index:** You look up "Photosynthesis" in the index, see it's on page 127, and go straight there.

Databases use indexes the same way: they maintain a separate lookup structure that lets them locate matching rows quickly instead of examining every row in the table.
