```c
#include <stdlib.h>   // malloc(), free()
#include <stddef.h>   // NULL (optional, see below)

struct Node
{
int data;
struct Node *next;
};


int main(){
    struct Node* head = malloc(sizeof(struct Node));


    if (head == NULL)
    {
        return 1; // allocation failed
    }

    head->data = 1;
    head->next = NULL;

    free(head);

    return 0;

}
```
