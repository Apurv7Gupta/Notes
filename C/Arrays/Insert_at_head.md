### Algorithm

1. Increase the size by 1.
2. Shift every element one position to the right.
3. Insert the new element at index `0`.
4. Print the updated array.

---

### C Program

```c
#include <stdio.h>

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int value = 5;


    for (int i = size; i > 0; i--)          // Shift every element to the right
    {
        arr[i] = arr[i - 1];
    }

    // Insert at beginning
    arr[0] = value;

    // Increase size
    size++;

    // Print updated array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

**Output**

```text
5 10 20 30 40 50
```

**Note:** Here `arr[10]` is necessary because you're inserting a new element. If the array were declared as:

```c
int arr[] = {10, 20, 30, 40, 50};
```
it would have space for only 5 elements, so inserting a sixth element would write past the end of the array (undefined behavior).
