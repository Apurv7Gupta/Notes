The four core built-in collection types are **list, tuple, set, and dictionary**.

| Type      | Syntax           | Ordered  | Mutable | Duplicates        | Indexed | Main Use                       |
| --------- | ---------------- | -------- | ------- | ----------------- | ------- | ------------------------------ |
| **list**  | `[]`             | ✅        | ✅       | ✅                 | ✅       | General collection             |
| **tuple** | `()`             | ✅        | ❌       | ✅                 | ✅       | Fixed data                     |
| **set**   | `{}`             | ❌        | ✅       | ❌                 | ❌       | Unique values, fast membership |
| **dict**  | `{"key": value}` | ✅ (3.7+) | ✅       | Keys: ❌ Values: ✅ | By key  | Key-value mapping              |

---

## 1. List

A dynamic array.

```python
nums = [10, 20, 30]

nums.append(40)
nums[1] = 25
print(nums[0])      # 10
```

Output:

```python
[10, 25, 30, 40]
```

Used for:

* API data
* JSON arrays
* Shopping carts
* Patients list

Example:

```python
patients = [
    {"id": 1, "name": "John"},
    {"id": 2, "name": "Emily"}
]
```

---

## 2. Tuple

Like a list, except immutable.

```python
point = (10, 20)

x = point[0]
```

Cannot do:

```python
point[0] = 5
```

Error:

```
TypeError: 'tuple' object does not support item assignment
```

Used for:

* Coordinates

```python
(4, 8)
```

* RGB

```python
(255, 120, 0)
```

* Returning multiple values

```python
def divide(a, b):
    return a // b, a % b

q, r = divide(10, 3)
```

---

## 3. Set

Stores only unique values.

```python
s = {1, 2, 3}

s.add(4)
s.add(2)

print(s)
```

Output:

```
{1,2,3,4}
```

Duplicate ignored.

Fast membership:

```python
if 5 in s:
    ...
```

Supports math operations:

```python
A = {1,2,3}
B = {3,4,5}

A | B   # union
A & B   # intersection
A - B   # difference
```

Result

```
Union        {1,2,3,4,5}
Intersection {3}
Difference   {1,2}
```

---

## 4. Dictionary

Maps keys to values.

```python
patient = {
    "id": 1,
    "name": "John",
    "age": 40
}
```

Access:

```python
patient["name"]
```

Output

```
John
```

Modify:

```python
patient["age"] = 41
```

Loop:

```python
for key, value in patient.items():
    print(key, value)
```

---

# Why your JSON became a list

JSON:

```json
[
  {"id":1,"name":"John"},
  {"id":2,"name":"Emily"}
]
```

becomes

```python
list[
    dict,
    dict
]
```

So

```python
data
```

looks like

```python
[
    {"id":1,...},
    {"id":2,...},
    {"id":3,...}
]
```

Hence

```python
for patient in data:
```

works.

---

# Dictionary vs List

Dictionary:

```python
patients = {
    1: {"name":"John"},
    2: {"name":"Emily"}
}
```

Lookup:

```python
patients[2]
```

O(1)

---

List:

```python
patients = [
    {"id":1},
    {"id":2},
    {"id":3}
]
```

Need to search:

```python
for p in patients:
    if p["id"] == 2:
        ...
```

O(n)

---

# Other built-in collection types

### String

```python
name = "John"
```

Sequence of characters.

Immutable.

---

### Range

```python
range(5)
```

Produces

```
0 1 2 3 4
```

Efficient for loops.

---

### Frozenset

Immutable set.

```python
fs = frozenset({1,2,3})
```

Cannot add/remove.

Useful as dictionary keys.

---

### Bytes

Immutable bytes.

```python
b = b"hello"
```

Networking, files, images.

---

### Bytearray

Mutable bytes.

```python
b = bytearray(b"hello")
```

Can modify.

---

## Quick rule of thumb

| Need                    | Use                   |
| ----------------------- | --------------------- |
| Ordered collection      | `list`                |
| Fixed ordered values    | `tuple`               |
| Unique values           | `set`                 |
| Key → value lookup      | `dict`                |
| Immutable unique values | `frozenset`           |
| Text                    | `str`                 |
| Binary data             | `bytes` / `bytearray` |

For FastAPI and REST APIs, you'll spend most of your time using:

* **`dict`** → JSON objects (`{"name": "John"}`)
* **`list`** → JSON arrays (`[{}, {}, {}]`)

Most API responses are simply **lists of dictionaries**.
