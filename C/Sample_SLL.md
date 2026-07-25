```c
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

Print the list
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
