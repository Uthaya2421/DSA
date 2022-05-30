#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int pow;
    int coeff;
    struct node *next;
} node;

void create(node **head, int pow)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *last = *head;

    new_node->pow = pow;
    scanf("%d", &new_node->coeff);
    new_node->next = NULL;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void poly_merge(node *poly1, node *poly2, node **poly3)
{
    node *last = *poly3;
    int pow = poly1->pow + poly2->pow;

    for (node *tmp = poly1->next; tmp != NULL; tmp = tmp->next, pow--)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->coeff = tmp->coeff;
        new_node->pow = pow;
        new_node->next = NULL;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = new_node;
    }

    for (node *tmp = poly2; tmp != NULL; tmp = tmp->next, pow--)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->coeff = tmp->coeff;
        new_node->pow = pow;
        new_node->next = NULL;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = new_node;
    }
}

void show(node *head)
{
    if (head->pow > 0 && head->coeff != 0)
    {
        printf("%dx^%d", head->coeff, head->pow);
    }
    else if (head->pow == 0)
    {
        printf("%d", head->coeff);
        printf("\n");
        return;
    }
    else if (head->pow == 1 && head->coeff == 0)
    {
        printf("%d", head->next->coeff);
        printf("\n");
        return;
    }
    for (node *temp = head->next; temp != NULL; temp = temp->next)
    {
        if (temp->coeff != 0)
        {
            if (temp->pow != 0)
            {
                if (temp->coeff > 0)
                {
                    printf(" + %dx^%d", abs(temp->coeff), temp->pow);
                }
                else
                {
                    printf(" - %dx^%d", abs(temp->coeff), temp->pow);
                }
            }
            else
            {
                if (temp->coeff > 0)
                {
                    printf(" + %d", abs(temp->coeff));
                }
                else
                {
                    printf(" - %d", abs(temp->coeff));
                }
            }
        }
    }
    printf("\n");
}

int power(int value, int exp)
{
    int res = 1;
    for (int i = 0; i < exp; i++)
    {
        res *= value;
    }
    return res;
}

int eval(node *poly, int value)
{
    int ans = 0;
    for (node *tmp = poly; tmp != NULL; tmp = tmp->next)
    {
        ans += tmp->coeff * power(value, tmp->pow);
    }
    return ans;
}

void free_list(struct node *head)
{
    struct node *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{

    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    int value;

    // Creating poly1.

    node *n = (node *)malloc(sizeof(node));
    scanf("%d", &n->pow);
    scanf("%d", &n->coeff);
    n->next = NULL;
    poly1 = n;
    for (int i = n->pow - 1; i >= 0; i--)
    {
        create(&poly1, i);
    }

    // Creating poly2.

    n = (node *)malloc(sizeof(node));
    scanf("%d", &n->pow);
    scanf("%d", &n->coeff);
    n->next = NULL;
    poly2 = n;
    for (int i = n->pow - 1; i >= 0; i--)
    {
        create(&poly2, i);
    }

    // Creating poly3.

    int pow = poly1->pow + poly2->pow + 1;

    node *new_node = (node *)malloc(sizeof(node));
    new_node->coeff = poly1->coeff;
    new_node->pow = pow;
    new_node->next = NULL;
    poly3 = new_node;

    poly_merge(poly1, poly2, &poly3);

    scanf("%d", &value);

    // Printing outputs.

    printf("P1(x) = ");
    show(poly1);

    printf("P2(x) = ");
    show(poly2);

    printf("P3(x) = ");
    show(poly3);

    printf("P1(%d) = %d\n", value, eval(poly1, value));
    printf("P2(%d) = %d\n", value, eval(poly2, value));
    printf("P3(%d) = %d\n", value, eval(poly3, value));

    // Freeing the memory allocated dynamically
    free_list(poly1);
    free_list(poly2);
    free_list(poly3);
}
