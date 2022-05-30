#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *url;
    struct node *prev;
    struct node *next;
} node;

void display(node *ptr)
{
    if (ptr->prev == NULL)
        printf("none ");
    else
        printf("%s ", ptr->prev->url);
    printf("%s ", ptr->url);
    if (ptr->next == NULL)
        printf("none\n");
    else
        printf("%s\n", ptr->next->url);
}

node *create(node **root)
{
    node *last = *root;
    // node *tmp = *temp;
    node *n = (node *)malloc(sizeof(node));
    char *c = (char *)malloc(20);
    scanf("%s", c);

    if (last->next == NULL)
    {
        n->url = c;
        n->prev = last;
        n->next = NULL;
        last->next = n;
    }
    else
    {
        last->next->url = c;
        last->next->prev = last;
        last->next->next = NULL;
    }

    return last->next;
}

node *back(node *temp, int val)
{
    for (int i = val; i > 0; i--)
    {
        if (temp->prev != NULL)
        {
            temp = temp->prev;
        }
        else
        {
            printf("%d back not possible\n", i);
            break;
        }
    }
    return temp;
}

node *forward(node *temp, int val)
{
    for (int i = val; i > 0; i--)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        else
        {
            printf("%d forward not possible\n", i);
            break;
        }
    }
    return temp;
}

void move(node *temp, int val)
{
    if (val > 0)
    {
        for (int i = val; i > 0; i--)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                printf("none\n");
                return;
            }
        }
        printf("%s\n", temp->url);
    }
    else
    {
        val = abs(val);
        for (int i = val; i > 0; i--)
        {
            if (temp->prev != NULL)
            {
                temp = temp->prev;
            }
            else
            {
                printf("none\n");
                return;
            }
        }
        printf("%s\n", temp->url);
    }
}
void del(node **temp, int val)
{
    node *last = *temp;
    if (val > 0)
    {
        for (int i = val; i > 0; i--)
        {
            if (last->next != NULL)
            {
                last = last->next;
            }
            else
            {
                printf("none\n");
                return;
            }
        }
        last->prev->next = last->next;
        if (last->next != NULL)
        {
            last->next->prev = last->prev;
        }
        free(last);
    }
    else
    {
        val = abs(val);
        for (int i = val; i > 0; i--)
        {
            if (last->prev != NULL)
            {
                last = last->prev;
            }
            else
            {
                printf("none\n");
                return;
            }
        }
        last->next->prev = last->prev;

        if (last->prev != NULL)
        {
            last->prev->next = last->next;
        }
        free(last);
    }
}

int main(void)
{
    node *root = NULL;
    node *temp;

    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == 'V')
        {
            if (root == NULL)
            {
                node *n = (node *)malloc(sizeof(node));
                char *s = (char *)malloc(20);
                scanf("%s", s);
                n->url = s;
                n->prev = NULL;
                n->next = NULL;
                root = n;
                temp = root;
                display(temp);
            }
            else
            {
                temp = create(&temp);
                display(temp);
            }
        }
        else if (c == 'B')
        {
            int val;
            scanf("%d", &val);
            temp = back(temp, val);
            display(temp);
        }
        else if (c == 'F')
        {
            int val;
            scanf("%d", &val);
            temp = forward(temp, val);
            display(temp);
        }
        else if (c == 'Q')
        {
            int val;
            scanf("%d", &val);
            move(temp, val);
        }
        else if (c == 'D')
        {
            int val;
            scanf("%d", &val);
            del(&temp, val);
            display(temp);
        }
        else if (c == 'E')
            exit(0);
    }
}