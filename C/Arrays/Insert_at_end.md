### Algorithm

1. Insert the new element at index `size`.
2. Increase the size by 1.
3. Print the updated array.

---

### C Program

```c
#include <stdio.h>

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int value = 60;

    // Insert at end
    arr[size] = value;

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
10 20 30 40 50 60
```

No shifting is required because the new element is simply placed after the last existing element.
