#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// A structure to represent a stack
typedef struct node
{
    char *data;
    struct node *next;
} node;

// A structure to represent a stack
typedef struct node1
{
    int data;
    struct node1 *next;
} node1;

void push(node **root, char *data)
{
    // printf("%s", data);
    node *stackNode = (node *)malloc(sizeof(node));
    stackNode->data = data;
    // printf("%s pushed to stack\n", stackNode->data);
    stackNode->next = *root;
    *root = stackNode;
}

void push1(node1 **root1, int data)
{
    node1 *stackNode = (node1 *)malloc(sizeof(node1));
    stackNode->data = data;
    stackNode->next = *root1;
    *root1 = stackNode;
}

char *pop(node **root)
{
    char *s = "error";
    if (*root == NULL)
    {
        printf("error");
        exit(0);
    }
    else
    {
        node *temp = *root;
        *root = (*root)->next;
        char *popped = temp->data;
        // free(temp);
        return popped;
    }
}

int pop1(node1 **root1)
{
    if (*root1 == NULL)
        return 0;
    else
    {
        node1 *temp = *root1;
        *root1 = (*root1)->next;
        int popped = temp->data;
        return popped;
    }
}

void postfix_infix(char *s)
{
    node *root = NULL;
    char *op1, *op2;
    char c[10];
    char *u;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            char *s2;
            s2 = (char *)malloc(20);
            c[0] = s[i];
            c[1] = '\0';
            strcpy(s2, c);
            push(&root, s2);
        }
        else if (s[i] == '^')
        {
            char *temp = (char *)malloc(10);
            char *s2;
            s2 = (char *)malloc(20);
            c[0] = s[i];
            c[1] = '\0';
            strcpy(s2, c);
            op1 = pop(&root);

            strcpy(temp, "(");
            strcat(temp, op1);
            strcat(temp, s2);
            strcat(temp, ")");
            push(&root, temp);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            char *temp = (char *)malloc(100);
            char *s2;
            s2 = (char *)malloc(20);
            c[0] = s[i];
            c[1] = '\0';
            strcpy(s2, c);
            op1 = pop(&root);
            // printf("popped %s", op1);
            op2 = pop(&root);
            // printf("popped %s", op2);

            strcpy(temp, "(");
            strcat(temp, op2);
            strcat(temp, s2);
            strcat(temp, op1);
            strcat(temp, ")");
            push(&root, temp);
        }
    }
    for (node *tmp = root; tmp != NULL; tmp = tmp->next)
    {
        printf("%s\n", tmp->data);
    }
}

void eval(char *s)
{
    node1 *root1 = NULL;
    int op1, op2, res;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            int a = malloc(sizeof(int));
            a = (int)(s[i] - '0');

            push1(&root1, a);
        }
        else if (s[i] == '^')
        {
            op1 = pop1(&root1);
            res = op1 * op1;

            push1(&root1, res);
        }
        else if (s[i] == '+')
        {
            op1 = pop1(&root1);
            op2 = pop1(&root1);

            res = op2 + op1;
            push1(&root1, res);
        }
        else if (s[i] == '-')
        {
            op1 = pop1(&root1);
            op2 = pop1(&root1);

            res = op2 - op1;
            push1(&root1, res);
        }
        else if (s[i] == '*')
        {
            op1 = pop1(&root1);
            op2 = pop1(&root1);

            res = op2 * op1;
            push1(&root1, res);
        }
        else if (s[i] == '/')
        {
            op1 = pop1(&root1);
            op2 = pop1(&root1);

            res = op2 / op1;
            push1(&root1, res);
        }
    }
    for (node1 *tmp = root1; tmp != NULL; tmp = tmp->next)
    {
        printf("%d", tmp->data);
    }
}

int main()
{
    char postfix[100];
    scanf("%s", postfix);
    postfix_infix(postfix);
    eval(postfix);
}