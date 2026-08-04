Common database indexing optimization techniques:

1. **Create indexes on frequently queried columns**

   * Columns used in `WHERE`, `JOIN`, `ORDER BY`, and `GROUP BY`.

   ```sql
   CREATE INDEX idx_email ON users(email);
   ```

2. **Use composite (multi-column) indexes**

   * Index columns that are commonly queried together.
   * Put the most selective or most frequently filtered column first.

   ```sql
   CREATE INDEX idx_name_age ON users(last_name, age);
   ```

   Works well for:

   ```sql
   WHERE last_name = 'Smith' AND age > 30
   ```

3. **Create covering indexes**

   * Include all columns required by a query so the database doesn't need to access the table.

   ```sql
   SELECT name, email
   FROM users
   WHERE id = 10;
   ```

   Index:

   ```sql
   CREATE INDEX idx_cover ON users(id, name, email);
   ```

4. **Use unique indexes when appropriate**

   * Improves lookup performance while enforcing uniqueness.

   ```sql
   CREATE UNIQUE INDEX idx_username ON users(username);
   ```

5. **Avoid over-indexing**

   * Every index speeds up reads but slows down `INSERT`, `UPDATE`, and `DELETE`.
   * Only create indexes that are actually used.

6. **Index foreign keys**

   * Improves join performance.

   ```sql
   CREATE INDEX idx_customer_id ON orders(customer_id);
   ```

7. **Use clustered indexes wisely**

   * Since table data is physically ordered by the clustered index (where supported), choose columns used for range queries or primary access paths.

8. **Use partial/filtered indexes**

   * Index only rows that are frequently queried.

   ```sql
   CREATE INDEX idx_active_users
   ON users(status)
   WHERE status = 'active';
   ```

9. **Use function/expression indexes**

   * Useful when queries apply functions to indexed columns.

   ```sql
   CREATE INDEX idx_lower_email
   ON users(LOWER(email));
   ```

10. **Regularly rebuild or reorganize indexes**

    * Reduces fragmentation and maintains performance, especially in write-heavy databases.

11. **Remove unused indexes**

    * Saves storage and improves write performance.

12. **Analyze query execution plans**

    * Use tools like `EXPLAIN` or `EXPLAIN ANALYZE` to verify that indexes are actually being used.

13. **Choose the appropriate index type**

    * **B-tree:** General-purpose, equality and range searches.
    * **Hash:** Fast equality lookups (database-dependent).
    * **Bitmap:** Low-cardinality columns in data warehouses.
    * **GIN/GiST:** Full-text search, arrays, JSON, spatial data (supported in some databases).

14. **Keep index keys narrow**

    * Smaller index keys reduce storage and improve cache efficiency.

15. **Maintain database statistics**

    * Updated statistics help the query optimizer choose the best execution plan.

### Best Practices

* Index columns used frequently in filters and joins.
* Use composite indexes for common multi-column queries.
* Avoid indexing columns with very low selectivity unless using specialized index types.
* Periodically monitor index usage and remove redundant indexes.
* Test index effectiveness using execution plans rather than assuming an index will help.
