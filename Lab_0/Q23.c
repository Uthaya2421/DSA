#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *name;
    int marks;
    struct node *ptr;
} node;

int main(void)
{

    node *link = NULL;

    node *n = malloc(sizeof(node));
    n->name = "Uthaya";
    n->marks = 90;
    n->ptr = NULL;

    link = n;

    n = malloc(sizeof(node));
    n->name = "Ashu";
    n->marks = 80;
    n->ptr = NULL;

    link->ptr = n;

    for (node *temp = link; temp != NULL; temp = temp->ptr)
    {
        printf("Name : %s\nMarks : %d\n", temp->name, temp->marks);
    }
    free(link->ptr);
    free(link);

    return 0;
}