Deleting from the beginning means:
- shifting every element one position to the left
- then decreasing the array size.

```c
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    // shifting every element to the left.
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    // dec the size
    size--;

    // Print updated array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
```
