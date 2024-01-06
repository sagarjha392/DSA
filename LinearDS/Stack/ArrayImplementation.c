#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4

int stack_arr[MAX]; // global declaration stack
int top = -1;       // top = -1 means stack is empty

void printStack(int stack[])
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

int peek(int i)
{
    if (top - i + 1 < 0)
    {
        printf("Invalid position");
        return -1;
    }
    else
    {
        return stack_arr[top - i + 1];
    }
}

bool isfull()
{
    bool value = false;

    if (top == MAX - 1)
    {
        value = true;
    }

    return value;
}

bool isempty()
{
    bool value = false;

    if (top == -1)
    {
        value = true;
    }

    return value;
}

void push(int data)
{

    if (isfull())
    {
        printf("Stack overflow");
    }
    else
    {
        top = top + 1;
        stack_arr[top] = data;
    }
}

int pop()
{
    if (isempty())
    {
        printf("\nStack underflow:\n");
        exit(1);
    }

    int value;
    value = stack_arr[top];
    top = top - 1;

    return value;
}
int main()
{
    int data;
    push(1);
    push(2);
    push(3);
    data = pop();
    push(4);
    printStack(stack_arr);
    printf("\nRemoved Element: %d\n", data);

    int x = peek(5);
    printf("\n%d\n", x);
    return 0;
}