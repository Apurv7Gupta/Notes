### Equality & Identity

- `==` compares values → both lists contain `[1, 2]`.
- `is` compares object identity → these are two different list objects.

```python
a = [1, 2]
b = [1, 2]
print(a == b)  # true
print(a is b)  # false
```

```python
a = None
print(a is None)  # true
print(a == None)  # true
```

```python
a = 256
b = 256
print(a is b)  # true

# CPython caches small integers (typically from -5 to 256). Both variables point to the same cached integer object.
```

```python
a = 1000
b = 1000
print(a is b)  # false

# It may print True or False depending on the Python implementation, version, and context.
```

---

### Mutable vs Immutable

```python
a = [1, 2]
b = a
b.append(3)
print(a) # [1, 2, 3]

# Lists are mutable, meaning they can be changed.
# b = a doesn't create a copy—it makes b refer to the same list.
# b.append(3) modifies that shared list, so a also changes.
```

```python
a = (1, 2)
b = a
print(a is b) # True

#Tuples are immutable, so they cannot be modified.

# Since there's no risk of either variable changing the tuple, Python simply has both a and b reference the same tuple object.

# Therefore, a is b is True.
```

```python
a = [1, 2]
b = a.copy()
b.append(3)

print(a) # => [1, 2]
print(b) # => [1, 2, 3]
```

---

### Default Mutable Arguments

Default arguments are evaluated once, when the function is defined—not every time it's called.

```python
def f(x=[]):
    x.append(1)
    return x

print(f())
print(f())
print(f())

# [1]
# [1, 1]
# [1, 1, 1]
```

```python
Function definition:
x ───► []

1st call:
[] → [1]

2nd call:
[1] → [1, 1]

3rd call:
[1, 1] → [1, 1, 1]
```

Correct Way:

```python
def f(x=None):
    if x is None:
        x = []
    x.append(1)
    return x
    
  print(f())   # [1]
	print(f())   # [1]
	print(f())   # [1]
```

```python
default x ───► None
1) f()
	x ───► None
	       │
	       ▼
			x ───► []
		

	x = []
	append(1)
	
	x ───► [1]
	return [1]
	
2) f()
x ───► None
       │
       ▼
		x = []      # brand new list

append(1)
x ───► [1] 

# This is not the previous list. It's a completely new object
```

---

### Copy vs Deep Copy

`deepcopy` Creates **completely new objects recursively**.

```python
import copy

a = [[1], [2]]
b = copy.copy(a)
c = copy.deepcopy(a)

a[0].append(99)

print(b)
print(c)
```

`copy` Creates a **new outer list**, but the inner lists are **shared**.

```python
a
 │
 ▼
+----------------+
|  *  |  *       |
+--|--+--|-------+
   |     |
   ▼     ▼
 [1]   [2]
 
 The outer list contains two references to two inner lists.
```

using `copy`,  Python creates a new outer list, but it doesn't copy the inner lists.

```python
a                     b
 │                     │
 ▼                     ▼
+----------------+   +----------------+
|  *  |  *       |   |  *  |  *       |
+--|--+--|-------+   +--|--+--|-------+
   |     |              |     |
   └─────┼──────────────┘     |
         └────────────────────┘
               ▼
             [1]   [2]
```

- `a` and `b` are different lists.
- But both point to the **same inner lists**.

---

### Variable References

```python
a = [1, 2]
b = a
a = [3, 4]
print(b) # => [1, 2]
```

People often confuse:

```python
a= [3,4]
```

with

```python
a[:]= [3,4]
```

The second one **modifies** the existing list, so `b` would also see the change.

---

### String Interning

```python
a = "hello"
b = "hello"
print(a is b) # True

Because of Python Interning
Instead of creating two "hello" objects, it reuses one to save space
```

```python
a = "".join(["he", "llo"])
b = "hello"
print(a == b)  # True
print(a is b) # false

# "".join(...) creates a new string object at runtime.
```

---

### List Multiplication Trap

```python
arr = [[0] * 3] * 3
arr[0][0] = 1
print(arr) # [[1, 0, 0], [1, 0, 0], [1, 0, 0]]

# you're modifying that one shared list.
```

`[0]*3` creates `[0, 0, 0]` 

but `[[0, 0, 0]] * 3` does NOT create three inner lists

It creates **three references to the same inner list**.

Correct way

```python
arr= [[0]*3 for _ inrange(3)]

# Now

arr[0][0] = 1
print(arr)

# [[1, 0, 0],
# [0, 0, 0],
# [0, 0, 0]]
```

---

### Closures

```python
funcs = []
for i in range(3):
    funcs.append(lambda: i)

print([f() for f in funcs])
```

---

### LEGB Scope

```python
x = 10
deff():
    x = 20

f()
print(x)
```

---

### `args` and `*kwargs`

- `a` → the first required positional argument.
- `args` → collects any extra positional arguments into a tuple.
- `*kwargs` → collects any keyword (named) arguments into a dictionary.

```python
def f(a, *args, **kwargs):
    print(a)
    print(args)
    print(kwargs)

f(1, 2, 3, x=4, y=5)
```

Python assigns them like this: `a=1      args= (2,3)     kwargs= {"x":4,"y":5}`

So the output is:

```
1
(2, 3)
{'x': 4, 'y': 5}
```

`*` and `**`

```python
def f(a, b, c):
    print(a, b, c)

nums = (1, 2, 3)
f(*nums)          # Unpacks tuple

======================================

def greet(name, age):
    print(name, age)

data = {"name": "Alice", "age": 20}
greet(**data)     # Unpacks dictionary
```

---

### Truthiness

```python
print(bool([]))     # False
print(bool({}))     # False
print(bool(""))     # False
print(bool(0))      # False
print(bool(None))   # False
```

```python
All these values will be False:

	False
	None
	Numeric zeroes: 0, 0.0, 0j
	Empty sequences: "", (), [], range(0)
	Empty collections: {}, set(), frozenset()
	Empty bytes: b"", bytearray(b"")
	
	===================================
	
Else all are True:
	
	bool([1])      # True
	bool("hi")     # True
	bool(42)       # True
	bool(-1)       # True
	bool({1: 2})   # True
	bool(set([1])) # True
```

---

### `==` vs `is` with Custom Objects

```python
class A:
    def __init__(self, x):
        self.x = x

    def __eq__(self, other):
        return self.x == other.x

a = A(1)
b = A(1)

print(a == b) # True
print(a is b) # False
```

## Search for these topics

If you're preparing for Python interviews, search for:

- **Python output prediction questions**
- **Python tricky interview questions**
- **Python core concepts interview questions**
- **Python internals interview questions**
- **Python object model interview questions**
- **Python gotchas**
- **Python edge cases**
- **Python language semantics**
- **Python memory model**
- **Python mutability interview questions**
