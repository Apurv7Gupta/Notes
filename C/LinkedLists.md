Linked lists are one of the most important data structures in C because they let you store data dynamically without requiring contiguous memory. They're used in operating systems, compilers, databases, memory allocators, and many real-world software systems.

---

# 1. What is a Linked List?

A linked list is a collection of **nodes** connected through pointers.

Each node contains:

* Data
* Pointer to the next node

```
+------+------+
| Data | Next | ------>
+------+------+

```

Example:

```
10 -> 20 -> 30 -> NULL

```

Memory:

```
Address      Value

1000         [10 | 2000]
2000         [20 | 3000]
3000         [30 | NULL]

```

Unlike arrays:

* Array elements are contiguous.
* Linked list nodes can be anywhere in memory.

---

# 2. Why Use Linked Lists?

Advantages

* Dynamic size
* Easy insertion
* Easy deletion
* No memory wastage due to fixed size

Disadvantages

* Extra memory for pointers
* No random access
* Slower traversal than arrays
* Poor cache locality

---

# 3. Structure of a Node

```c
struct Node
{
    int data;
    struct Node *next;
};
```

or

```c
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
```

Now:

```c
Node *head = NULL;
```

---

# 4. Memory Allocation

Create a node:

```c
Node *newNode = malloc(sizeof(Node));

newNode->data = 10;
newNode->next = NULL;
```

Always check:

```c
if(newNode == NULL)
{
    printf("Memory allocation failed");
    exit(1);
}
```

---

# 5. Head Pointer

```
head
 |
 v
10 -> 20 -> 30 -> NULL
```

If

```c
head = NULL;
```

the list is empty.

---

# 6. Traversing

```c
void display(Node *head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
```

Time Complexity:

```
O(n)
```

---

# 7. Creating a Linked List

```c
Node *createNode(int value)
{
    Node *node = malloc(sizeof(Node));

    node->data = value;
    node->next = NULL;

    return node;
}
```

---

# 8. Insert at Beginning

Before

```
20 -> 30
```

Insert 10

```
10 -> 20 -> 30
```

```c
void insertFront(Node **head, int value)
{
    Node *node = createNode(value);

    node->next = *head;
    *head = node;
}
```

Time

```
O(1)
```

---

# 9. Insert at End

```
10 -> 20 -> NULL
```

Insert 30

```
10 -> 20 -> 30 -> NULL
```

```c
void insertEnd(Node **head, int value)
{
    Node *node = createNode(value);

    if(*head == NULL)
    {
        *head = node;
        return;
    }

    Node *temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = node;
}
```

Time

```
O(n)
```

---

# 10. Insert at Position

Example

```
10 20 40
```

Insert 30 at position 3

```
10 20 30 40
```

Steps

1. Traverse
2. Reach previous node
3. Adjust pointers

---

# 11. Delete First Node

Before

```
10 -> 20 -> 30
```

After

```
20 -> 30
```

```c
void deleteFront(Node **head)
{
    if(*head == NULL)
        return;

    Node *temp = *head;

    *head = (*head)->next;

    free(temp);
}
```

---

# 12. Delete Last Node

```c
void deleteEnd(Node **head)
{
    if(*head == NULL)
        return;

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;

    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);

    temp->next = NULL;
}
```

---

# 13. Delete by Value

Find

```
10 -> 20 -> 30 -> 40
```

Delete

```
30
```

Result

```
10 -> 20 -> 40
```

---

# 14. Searching

```c
Node *search(Node *head, int key)
{
    while(head)
    {
        if(head->data == key)
            return head;

        head = head->next;
    }

    return NULL;
}
```

Time

```
O(n)
```

---

# 15. Count Nodes

```c
int count(Node *head)
{
    int c = 0;

    while(head)
    {
        c++;
        head = head->next;
    }

    return c;
}
```

---

# 16. Reverse Linked List

Original

```
1 -> 2 -> 3 -> NULL
```

Reverse

```
3 -> 2 -> 1 -> NULL
```

Algorithm

Need

```
prev
curr
next
```

Code

```c
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
```

Time

```
O(n)
```

Space

```
O(1)
```

---

# 17. Recursive Reverse

```c
Node *reverse(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverse(head->next);

    head->next->next = head;

    head->next = NULL;

    return newHead;
}
```

---

# 18. Middle Element

Fast and Slow Pointer

```
Fast: 2 steps

Slow: 1 step
```

When fast reaches end,

slow is at middle.

```c
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```

---

# 19. Detect Loop (Floyd's Cycle Detection)

```
slow

fast
```

If they meet

Cycle exists.

```c
int hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }

    return 0;
}
```

Time

```
O(n)
```

---

# 20. Remove Loop

After detection:

1. Find meeting point
2. Move one pointer to head
3. Move both one step
4. Break the loop

---

# 21. Merge Two Sorted Lists

Example

```
1 4 7

2 3 9

↓

1 2 3 4 7 9
```

Time

```
O(m+n)
```

---

# 22. Merge Sort on Linked List

Steps

1. Find middle
2. Split
3. Sort both halves
4. Merge

Complexity

```
O(n log n)
```

---

# 23. Remove Duplicates

Sorted

```
1 1 2 2 3 4 4
```

↓

```
1 2 3 4
```

---

# 24. Rotate List

```
1 2 3 4 5

Rotate 2

↓

4 5 1 2 3
```

---

# 25. Nth Node from End

Fast pointer moves N nodes.

Then move both pointers.

When fast reaches NULL,

slow points to answer.

---

# 26. Palindrome Linked List

```
1 2 3 2 1
```

Method

* Find middle
* Reverse second half
* Compare halves

---

# 27. Types of Linked Lists

## Singly Linked List

```
10 -> 20 -> 30
```

One pointer

```
next
```

---

## Doubly Linked List

Each node

```
prev

data

next
```

```
NULL <- 10 <-> 20 <-> 30 -> NULL
```

Advantages

* Traverse both directions
* Easy deletion

Disadvantages

* Extra memory

Structure

```c
typedef struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;
```

---

## Circular Linked List

```
1 -> 2 -> 3
^         |
|_________|
```

Last points back to first.

Useful for:

* CPU scheduling
* Round-robin algorithms
* Music playlists
* Multiplayer turn systems

---

## Circular Doubly Linked List

```
<-> <-> <->

Last links first

First links last
```

---

# 28. Time Complexity

| Operation              | Singly | Doubly                      |
| ---------------------- | ------ | --------------------------- |
| Access                 | O(n)   | O(n)                        |
| Search                 | O(n)   | O(n)                        |
| Insert Front           | O(1)   | O(1)                        |
| Insert End (no tail)   | O(n)   | O(n)                        |
| Insert End (with tail) | O(1)   | O(1)                        |
| Delete Front           | O(1)   | O(1)                        |
| Delete End (no tail)   | O(n)   | O(1) (with tail and `prev`) |
| Reverse                | O(n)   | O(n)                        |

---

# 29. Common Interview Problems

* Reverse list
* Reverse in groups of K
* Detect cycle
* Remove cycle
* Merge sorted lists
* Merge sort
* Remove duplicates
* Rotate list
* Add two numbers as lists
* Intersection of two lists
* Clone list with random pointer
* Flatten multilevel list
* LRU Cache (Doubly Linked List + Hash Map)
* Skip List
* XOR Linked List (rare)

---

# 30. Common Mistakes

* Forgetting `malloc()` failure checks.
* Forgetting `free()` (memory leaks).
* Accessing `temp->next` when `temp` is `NULL`.
* Losing the head pointer by overwriting it during traversal.
* Not updating the head after inserting/deleting the first node.
* Freeing a node before saving its `next` pointer if you still need it.
* Creating cycles accidentally by assigning `next` incorrectly.
* Dereferencing freed memory (use-after-free).
* Double-freeing the same node.
* Forgetting to set `next` to `NULL` for the last node when appropriate.

---

# 31. Complete Example

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void insertEnd(Node **head, int value) {
    Node *node = createNode(value);

    if (*head == NULL) {
        *head = node;
        return;
    }

    Node *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = node;
}

void display(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    display(head);

    freeList(head);
    return 0;
}
```

This example follows good C practices by checking `malloc`, avoiding memory leaks, and separating node creation, insertion, traversal, and cleanup into reusable functions.
