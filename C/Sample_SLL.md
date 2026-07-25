### Create SLL

```c
#include <stdio.h>   // printf
#include <stdlib.h>   // malloc(), free()
#include <stddef.h>   // NULL (optional, Usually, <stdlib.h> is enough, because it also provides NULL on most implementations)

struct Node
{
int data;
struct Node *next;
};


int main(){
    // Allocate nodes
    struct Node *head = malloc(sizeof(struct Node));
    head->next = malloc(sizeof(struct Node));
    head->next->next = malloc(sizeof(struct Node));

    // [optional] Check malloc (of every node, here we check only for head)
    if (head == NULL)
    {
        return 1; // allocation failed
    }

    // Define the structure
    head->data = 1;
    head->next->data = 2;
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // free every node
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
```

### Print the list
 - Make sure you print before freeing

```c
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);

        if (temp->next)
            printf("->");

        temp = temp->next;
    }
```

### SLL from an array

```c
 int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create first node
    struct Node *head = malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    struct Node *tail = head;

    // Create remaining nodes
    for (int i = 1; i < size; i++)
    {
        tail->next = malloc(sizeof(struct Node));
        tail = tail->next;

        tail->data = arr[i];
        tail->next = NULL;
    }

    // Print list
    struct Node *temp = head;
    while (temp)
    {
        printf("%d", temp->data);

        if (temp->next)
            printf(" -> ");

        temp = temp->next;
    }
    printf(" -> NULL\n");

    // Free list
    temp = head;
    while (temp)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
```
