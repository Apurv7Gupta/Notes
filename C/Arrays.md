An **array** in C is a collection of elements of the **same data type** stored in **contiguous memory locations**.

## 1. Declaration of Array

### Syntax

```c
data_type array_name[size];
```

### Example

```c
int marks[5];
float salary[10];
char name[20];
```

---

## 2. Initialization of Array

### Method 1: Initialize at Declaration

```c
int arr[5] = {10, 20, 30, 40, 50};
```

### Method 2: Size Automatically Determined

```c
int arr[] = {10, 20, 30, 40, 50};
```

### Method 3: Partial Initialization

```c
int arr[5] = {10, 20};
```

Output:

```
10 20 0 0 0
```

---

## 3. Accessing Array Elements

Array indexing starts from **0**.

```c
int arr[5] = {10, 20, 30, 40, 50};

printf("%d", arr[0]); // 10
printf("%d", arr[2]); // 30
```

---

## 4. Input and Output in Arrays

### Input

```c
int arr[5];

for(int i=0; i<5; i++)
{
    scanf("%d", &arr[i]);
}
```

### Output

```c
for(int i=0; i<5; i++)
{
    printf("%d ", arr[i]);
}
```

---

## 5. Memory Representation

```c
int arr[5] = {10,20,30,40,50};
```

Suppose `arr` starts at address `1000`.

| Element | Value | Address |
| ------- | ----- | ------- |
| arr[0]  | 10    | 1000    |
| arr[1]  | 20    | 1004    |
| arr[2]  | 30    | 1008    |
| arr[3]  | 40    | 1012    |
| arr[4]  | 50    | 1016    |

(Assuming `int` = 4 bytes)

---

## 6. Array and Pointers

Array name represents the address of the first element.

```c
int arr[5] = {10,20,30,40,50};

printf("%d\n", arr[0]);
printf("%d\n", *(arr+0));

printf("%d\n", arr[2]);
printf("%d\n", *(arr+2));
```

Output:

```
10
10
30
30
```

---

## 7. Traversing an Array

```c
for(int i=0; i<5; i++)
{
    printf("%d ", arr[i]);
}
```

---

# Types of Arrays

## A. One-Dimensional Array

```c
int arr[5] = {1,2,3,4,5};
```

Representation:

```
[1][2][3][4][5]
```

---

## B. Two-Dimensional Array

Used for matrices.

### Declaration

```c
int arr[3][4];
```

### Initialization

```c
int arr[2][3] =
{
    {1,2,3},
    {4,5,6}
};
```

### Access

```c
printf("%d", arr[1][2]); // 6
```

### Input and Output

```c
for(int i=0;i<2;i++)
{
    for(int j=0;j<3;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}
```

---

## C. Multi-Dimensional Array

### 3D Array Example

```c
int arr[2][3][4];
```

Used in graphics, scientific computations, etc.

---

# Common Operations on Arrays

## 1. Find Sum

```c
int sum = 0;

for(int i=0;i<5;i++)
{
    sum += arr[i];
}
```

---

## 2. Find Maximum Element

```c
int max = arr[0];

for(int i=1;i<5;i++)
{
    if(arr[i] > max)
        max = arr[i];
}
```

---

## 3. Find Minimum Element

```c
int min = arr[0];

for(int i=1;i<5;i++)
{
    if(arr[i] < min)
        min = arr[i];
}
```

---

## 4. Search Element (Linear Search)

```c
int key = 30;

for(int i=0;i<5;i++)
{
    if(arr[i] == key)
    {
        printf("Found");
        break;
    }
}
```

---

## 5. Sort Array (Bubble Sort)

```c
for(int i=0;i<5-1;i++)
{
    for(int j=0;j<5-i-1;j++)
    {
        if(arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
```

---

# Passing Array to Function

```c
#include <stdio.h>

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
}

int main()
{
    int a[] = {1,2,3,4,5};

    display(a,5);

    return 0;
}
```

---

# Character Arrays (Strings)

```c
char name[20] = "Hello";
```

Or

```c
char name[] = {'H','e','l','l','o','\0'};
```

Print:

```c
printf("%s", name);
```

---

# Variable Length Arrays (VLA)

C99 introduced VLAs.

```c
int n;
scanf("%d", &n);

int arr[n];
```

Size is decided at runtime.

---

# Advantages of Arrays

1. Easy storage of multiple values.
2. Fast access using index.
3. Efficient memory usage.
4. Useful in sorting and searching.

---

# Limitations of Arrays

1. Fixed size (except VLAs).
2. Stores only same data type.
3. Insertion/deletion is costly.
4. Possible out-of-bounds errors.

---

# Important Interview Questions

### Difference between Array and Pointer

| Array                | Pointer                  |
| -------------------- | ------------------------ |
| Fixed memory block   | Variable storing address |
| Size fixed           | Can point anywhere       |
| Cannot be reassigned | Can be reassigned        |

### What is Array Index Out of Bounds?

```c
int arr[5];
arr[10] = 100; // Undefined behavior
```

### Why Array Index Starts from 0?

Because:

```c
arr[i] == *(arr + i)
```

The first element is at offset 0 from the base address.

---

## Example Program

```c
#include <stdio.h>

int main()
{
    int arr[5];
    int sum = 0;

    printf("Enter 5 numbers:\n");

    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    printf("Elements are: ");

    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nSum = %d",sum);

    return 0;
}
```
