## Expression Evaluation

A classic stack application is evaluating a postfix (Reverse Polish) expression.

### Example

Postfix expression: `23*54*+9-`

Equivalent infix: `(2 * 3) + (5 * 4) - 9`

Expected result: `17`

### Step-by-step evaluation

  | Symbol | Stack | Operation       |
| ------ | ----- | --------------- |
| 2      | 2     | Push            |
| 3      | 2 3   | Push            |
| *      | 6     | Pop 3,2 → 2×3   |
| 5      | 6 5   | Push            |
| 4      | 6 5 4 | Push            |
| *      | 6 20  | Pop 4,5 → 5×4   |
| +      | 26    | Pop 20,6 → 6+20 |
| 9      | 26 9  | Push            |
| -      | 17    | Pop 9,26 → 26−9 |


### Code

```c
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    top = top + 1;
    stack[top] = x;
}

int pop()
{
    int temp = stack[top];
    top = top - 1;
    return temp;
}

int main()
{
    char exp[] = "23*54*+9-";

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            push(ch - '0');   // Convert character to integer
        }
        else
        {
            int b = pop();
            int a = pop();

            switch (ch)
            {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
```

### Algorithm

- Scan the postfix expression from left to right.
- If the symbol is a number, push it onto the stack.
- If the symbol is an operator:
- Pop the top two numbers.
- Apply the operator (a op b).
- Push the result back onto the stack.
- After solving the entire expression, the only element left on the stack is the final result.


## Conversion of Infix to postfix expression

- Scan the infix expression from left to right.
- If the symbol is an operand, add it to the postfix expression.
- If it is '(', push it onto the stack.
- If it is ')', pop operators until '(' is found.
- If it is an operator, pop operators from the stack while they have higher or equal precedence, then push the current operator.
- After scanning the expression, pop all remaining operators from the stack.
- The resulting string is the postfix expression.

```c
char stack[MAX];
int top = -1;

// Push operation


// Pop operation


// Return top element
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Check precedence
int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
```



## Conversion of Infix to Prefix expression

- Reverse the infix expression.
- Replace every '(' with ')' and every ')' with '('.
- Convert the modified infix expression to postfix using a stack.
- Reverse the postfix expression.
- The reversed postfix expression is the required prefix expression.


```c

char stack[MAX];
int top = -1;

// Push operation

// Pop operation

// Peek operation
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Check precedence
int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Reverse string
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int i, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    // Step 1: Reverse infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert reversed infix to postfix
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    // Step 4: Reverse postfix to get prefix
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
```
