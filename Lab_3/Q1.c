#include <stdio.h>
#include <ctype.h>

int MaxSize = 100;
char stack[100];
int top = -1;

int isEmpty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MaxSize)
        return 1;
    else
        return 0;
}

void push(int ele)
{
    if (isFull)
        printf("Overflow");
    else
    {
        top++;
        stack[top] = ele;
    }
}

char pop()
{
    int ele;

    if (isEmpty)
        printf("Underflow");
    else
        return (stack[top--]);
}

int peek()
{
    return stack[top];
}

void postfix_infix(char exp[200])
{
    int a, b;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char op1, op2;

        if (isdigit(exp[i]))
        {
            push(exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            op1 = pop();
            op2 = pop();
            push("(" + op2 + exp[i] + op1 + ")")
        }
    }
}

int main(void)
{
    char str[200];

    scanf("%s", &str);
    printf("%s", str);
    return 0;
}