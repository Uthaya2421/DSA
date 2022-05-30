#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int pow;
    int coeff[20];
    struct node *next;
} node;

void show(node *n)
{
    if (n->pow > 0 && n->coeff[0] != 0)
    {
        printf("%dx^%d", n->coeff[0], n->pow);
    }
    else if (n->pow == 0)
    {
        printf("%d", n->coeff[0]);
        printf("\n");
        return;
    }
    else if (n->pow == 1 && n->coeff[0] == 0)
    {
        printf("%d", n->coeff[1]);
        printf("\n");
        return;
    }
    for (int i = 1, temp = n->pow - 1; i <= n->pow; i++, temp--)
    {
        if (n->coeff[i] != 0)
        {
            if (temp != 0)
            {
                if (n->coeff[i] > 0)
                {
                    printf(" + %dx^%d", abs(n->coeff[i]), n->pow);
                }
                else
                {
                    printf(" - %dx^%d", abs(n->coeff[i]), n->pow);
                }
            }
            else
            {
                if (n->coeff[i] > 0)
                {
                    printf(" + %d", abs(n->coeff[i]));
                }
                else
                {
                    printf(" - %d", abs(n->coeff[i]));
                }
            }
        }
    }
    printf("\n");
}

int expo(int value, int exp)
{
    int ans = 1;
    for (int i = 0; i < exp; i++)
    {
        ans *= value;
    }
    return ans;
}

int eval(node *n, int value)
{
    int res = 0;
    for (int i = 0, temp = n->pow; i <= n->pow; i++, temp--)
    {
        res += (n->coeff[i]) * (expo(value, temp));
    }
    return res;
}

int main(void)
{
    int value;

    node *list = NULL;

    node *n = (node *)malloc(sizeof(node));
    scanf("%d", &n->pow);
    for (int i = 0; i <= n->pow; i++)
    {
        scanf("%d", &n->coeff[i]);
    }
    n->next = NULL;
    list = n;

    n = (node *)malloc(sizeof(node));
    scanf("%d", &n->pow);
    for (int i = 0; i <= n->pow; i++)
    {
        scanf("%d", &n->coeff[i]);
    }
    n->next = NULL;
    list->next = n;

    n = (node *)malloc(sizeof(node));
    n->pow = (list->pow) + (list->next->pow) + 1;
    for (int i = 0; i <= list->pow; i++)
    {
        n->coeff[i] = list->coeff[i];
    }
    for (int i = 0; i <= list->next->pow; i++)
    {
        n->coeff[list->pow + i + 1] = list->next->coeff[i];
    }
    n->next = NULL;
    list->next->next = n;

    scanf("%d", &value);

    int count = 0;

    for (node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("P%d(x) = ", count + 1);
        show(temp);
        count++;
    }

    count = 1;

    for (node *temp = list; temp != NULL; temp = temp->next, count++)
    {
        printf("P%d(%d) = %d\n", count, value, eval(temp, value));
    }

    free(list->next->next);
    free(list->next);
    free(list);
}