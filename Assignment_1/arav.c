#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    struct Node *prev;
    char data[100];
    struct Node *next;
} *first = NULL, *curr = NULL;

struct Node *Display(struct Node *New)
{
    if (New->prev == NULL && New->next == NULL)
    {
        printf("None %s None\n", New->data);
    }
    else if (New->prev == NULL)
    {
        printf("none %s %s\n", New->data, New->next->data);
    }
    else if (New->prev == NULL && New->next != NULL)
    {
        printf("%s %s none", New->prev->data, New->data);
    }

    else if (New->next == NULL && New->prev->prev == NULL)
    {
        printf("%s %s none\n", New->prev->data, New->data);
    }
    else if (New->prev && New && New->next)
    {
        printf("%s %s %s\n", New->prev->data, New->data, New->next->data);
    }
    else if (New && New->prev != NULL && New->prev->prev != NULL)
    {
        printf("%s %s none\n", New->prev->data, New->data);
    }
    return curr;
}
int pos(struct Node *New);
int length(struct Node *New);

struct Node *create()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    scanf("%s", newnode->data);
    newnode->prev = newnode->next = NULL;
    if (first == NULL)
    {
        first = newnode;
        curr = first;
    }
    else
    {
        newnode->prev = curr;
        if (curr->next)
        {
            newnode->next = NULL;
        }

        // newnode->next = curr->next;
        curr->next = newnode;
        curr = newnode;
    }
    Display(curr);

    // printf("%s\n", curr->data);
    return curr;
}

int length(struct Node *New)
{

    int len = 0;
    while (New != NULL)
    {
        len++;
        New = New->next;
    }
    return len;
}

int pos(struct Node *New)
{

    int p = 0;
    while (New != curr)
    {
        p++;
        New = New->next;
    }
    return p;
}
struct Node *back()
{
    int a, b;
    scanf("%d", &a);
    b = pos(first);
    if (a > b)
    {
        for (int i = b; i > a - b; i--)
        {
            curr = curr->prev;
        }
        printf("%d back not possible\n", a - b);
    }
    else
    {
        for (int i = b; i > b - a; i--)
        {
            curr = curr->prev;
        }
        // printf("%s\n", curr->data);
        // printf("%d\n", pos(first));
    }
    Display(curr);
    return curr;
}
struct Node *forward()
{
    int a, b, c;
    c = length(first);
    scanf("%d", &a);
    b = pos(first);
    printf("%d\n", b);
    if (a > c - b - 1)
    {
        for (int i = b; i < c - b; i++)
        {
            curr = curr->next;
        }
        printf("%s \n", curr->data);
        int s = a - (c - b - 1);
        printf("%d forward not possible\n", s);
        printf("%s\n", curr->data);
        Display(curr);
    }
    else
    {
        for (int i = b; i < b + a; i++)
        {
            curr = curr->next;
        }
        Display(curr);
        // printf("%s\n", curr->data);
    }
    return curr;
}
void Delete()
{
    int b, c, d;
    scanf("%d", &b);

    struct Node *temp;
    temp = curr;
    if (b > 0)
    {
        for (int i = b; i > 0; i--)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
            else
            {
                printf("none\n");
                return;
            }
        }
        curr->prev->next = curr->next;
        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        free(curr);
        curr = temp;
    }
    else
    {
        b = abs(b);
        for (int i = b; i > 0; i--)
        {
            if (curr->prev != NULL)
            {
                curr = curr->prev;
            }
            else
            {
                printf("none\n");
                return;
            }
        }
        curr->next->prev = curr->prev;

        if (curr->prev != NULL)
        {
            curr->prev->next = curr->next;
        }
        free(curr);
        curr = temp;
    }
}
void show()
{
    int a, c, d;
    scanf("%d", &a);
    c = pos(first);
    d = length(first);
    printf("%d %d\n", c, d);
    struct Node *p;
    if ((a > 0) && (a < d - c - 1))
    {
        p = curr;
        for (int i = c; i <= c + a; i++)
        {
            p = p->next;
        }
        printf("%s\n", p->data);
    }
    else if (a == d - c - 1)
    {
        p = curr;
        p = p->next;
        printf("%s\n", p->data);
    }

    else if ((a < 0) && (abs(a) <= d - (d - c)))
    {
        p = curr;
        for (int i = c; i > c - abs(a); i--)
        {
            p = p->prev;
        }
        printf("%s\n", p->data);
    }
    else
    {
        printf("None\n");
    }
}

int main()
{
    while (1)
    {
        char menu[100];
        scanf("%s", menu);
        if (menu[0] == 'V')
        {
            create();
        }
        else if (menu[0] == 'B')
        {
            back();
        }

        else if (menu[0] == 'F')
        {
            forward();
        }
        else if (menu[0] == 'Q')
        {
            show();
        }

        else if (menu[0] == 'D')
        {
            Delete();
        }
        else if (menu[0] == 'E')
        {
            break;
        }
    }
    return 0;
}