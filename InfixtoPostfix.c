//Aim : To perform infix to postfix conversion using stack


#include <stdio.h>
#include <stdlib.h>

int top = -1, max;
char *stack;

void push(char item)
{
    if (top == max - 1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
char pop()
{
    char item;
    if (top == -1)
    {
        printf("Stack underflow/empty\n");
        return '\0';
    }
    else
    {
        char item = stack[top];
        top = top - 1;
        return item;
    }
}
char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top];
    }
}
int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &max);
    stack = (char *)malloc(max * sizeof(char));
    char infix[max];
    char postfix[max];
    printf("Please enter the infix string of size %d: ", max);
    scanf("%s", infix);
    int token_precedence, i = 0, j = 0;
    char c;
    while ((c = infix[i]) != '\0')
    {
        token_precedence = get_precedence(c);

        if (token_precedence > 0)
        {
            while (token_precedence <= get_precedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
        else
        {
            switch (c)
            {
            case '(':
                push(c);
                break;
            case ')':
                while (peek() != '(')
                {
                    postfix[j++] = pop();
                }
                pop(); // remove '('
                break;
            default:
                postfix[j++] = c;
                break;
            }
        }
        i++;
    }
    while (peek() != '\0')
    {
        char c = pop();
        printf("popped char %c",c);
        postfix[j++] = c;
    }
    postfix[j] = '\0';
    printf("Postfix notation is: %s\n", postfix);
    return 0;
}
