### Algorithm

1. Check if the array is empty. (optional)
2. Decrease the size by 1.
3. Print the remaining elements.

---

### C Program

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    // Delete last element
    size--;

    // Print updated array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

**Output**

```
10 20 30 40
```

Unlike deleting from the beginning, **no shifting is needed**. The last element is removed simply by reducing the logical size of the array.

### Why is this considered "deletion" when we're just printing till the second last element and calling the last element as "removed"?

In C, arrays cannot change size after they're created.

So "deleting an element" almost always means:

- updating a variable (size) that tracks how many elements are considered valid,
- and ignoring anything beyond that.

This is exactly how many real data structures (like stacks) work.
