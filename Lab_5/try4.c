#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left_ptr;
    struct node *right_ptr;
} node;

// creating stack
struct stack
{
    struct node *data;
    struct stack *next;
};

void push(struct stack **top, struct node *n)
{
    struct stack *new_n = (struct stack *)malloc(sizeof(struct stack));
    new_n->data = n;
    new_n->next = (*top);
    (*top) = new_n;
}
int isEmpty(struct stack *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
struct node *pop(struct stack **top_n)
{
    struct node *item;
    struct stack *top;
    top = *top_n;
    item = top->data;
    *top_n = top->next;
    free(top);
    return item;
}

// creating BST
void create(int postorder[], node **head, int size)
{
    node *last = *head;
    for (int i = size - 2; i >= 0; i--)
    {
        while (last != NULL)
        {
            if (last->value > postorder[i] && last->left_ptr == NULL)
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = postorder[i];
                n->left_ptr = NULL;
                n->right_ptr = NULL;
                last->left_ptr = n;
            }
            else if (last->value > postorder[i])
            {
                last = last->left_ptr;
            }
            else if (last->value < postorder[i] && last->right_ptr == NULL)
            {
                node *n = (node *)malloc(sizeof(node));
                n->value = postorder[i];
                n->left_ptr = NULL;
                n->right_ptr = NULL;
                last->right_ptr = n;
            }
            else
            {
                last = last->right_ptr;
            }
        }
        last = *head;
    }
}

node *search(node *root, int value)
{
    while (root->value != value)
    {
        if (value < root->value)
        {
            if (root->left_ptr == NULL)
                return NULL;
            root = root->left_ptr;
        }
        else if (value > root->value)
        {
            if (root->right_ptr == NULL)
                return NULL;
            root = root->right_ptr;
        }
    }
    return root;
}

struct node *in_order_predecessor(struct node *root, node *t)
{
    node *b;
    int c;
    if (root->left_ptr == NULL && root->right_ptr == NULL)
    {
        while (t->value != root->value)
        {
            if (root->value < t->value)
            {
                b = t;
                t = t->left_ptr;
                c = 0;
            }
            else if (root->value > t->value)
            {
                b = t;
                t = t->right_ptr;
                c = 1;
            }
        }
        if (c == 0)
        {
            b->left_ptr = NULL;
        }
        else
        {
            b->right_ptr = NULL;
        }
        return NULL;
    }
    struct node *tmp;
    if (root->left_ptr != NULL)
    {
        if (root->left_ptr->right_ptr == NULL && root->left_ptr->left_ptr == NULL)
        {
            tmp = root->left_ptr;
            root->left_ptr = NULL;
            return tmp;
        }
        root = root->left_ptr;
        while (root->right_ptr != NULL)
        {
            if (root->right_ptr->right_ptr == NULL && root->right_ptr->left_ptr == NULL)
            {
                tmp = root->right_ptr;
                root->right_ptr = NULL;
                return tmp;
            }
            root = root->right_ptr;
        }
        return root;
    }
    else
    {
        if (root->right_ptr->right_ptr == NULL && root->right_ptr->left_ptr == NULL)
        {
            tmp = root->right_ptr;
            root->right_ptr = NULL;
            return tmp;
        }
        root = root->right_ptr;
        return root;
    }
}

int delete_node(node *root, node *t, int value)
{
    node *ipre;

    if (root == NULL)
    {
        printf("empty");
        return 1;
    }

    else if (root->left_ptr == NULL && root->right_ptr == NULL)
    {

        free(root);
        return 0;
    }

    root = search(root, value);
    if (root == NULL)
    {
        printf("error");
        return 1;
    }
    else
    {
        ipre = in_order_predecessor(root, t);
        if (ipre != NULL)
        {
            root->value = ipre->value;
            delete_node(ipre, t, ipre->value);
        }
    }
}

int printPreorder(struct node *root)
{
    struct node *temp = root;
    struct stack *s_temp = NULL;
    int flag = 1;
    while (flag)
    {
        if (temp != NULL)
        {
            printf("%d ", temp->value);
            push(&s_temp, temp);
            temp = temp->left_ptr;
        }
        else
        {
            if (!isEmpty(s_temp))
            {
                temp = pop(&s_temp);
                temp = temp->right_ptr;
            }
            else
                flag = 0;
        }
    }
}

//----------------------------------------------------------//

void menu1(node *root)
{
    node *temp = root;
    struct stack *s_temp1 = NULL;
    struct stack *s_temp2 = NULL;
    struct stack *s_temp3 = NULL;
    push(&s_temp1, temp);
    int flag = 1, leaves = 0, h = 0, n = 0, i = 0;
    int l[10];

    while (flag)
    {
        if (!isEmpty(s_temp1))
        {
            temp = pop(&s_temp1);
            if (temp->left_ptr != NULL)
                push(&s_temp2, temp->left_ptr);
            if (temp->right_ptr != NULL)
                push(&s_temp2, temp->right_ptr);
            if (temp->left_ptr == NULL && temp->right_ptr == NULL)
                leaves += 1;
            n++;
        }
        else if (!isEmpty(s_temp2))
        {
            l[i] = h;
            h++;
            i++;
            l[i] = n;
            i++;
            n = 0;

            s_temp1 = s_temp2;

            s_temp2 = NULL;
        }
        else
        {
            l[i] = h;
            h++;
            i++;
            l[i] = n;
            i++;
            flag = 0;
        }
    }
    printf("%d\n", leaves);
    printf("%d\n", l[i - 2] + 1);
    for (int j = 0; j < i; j += 2)
    {
        printf("%d %d\n", l[j], l[j + 1]);
    }
}

//-----------------------------------------------------------//

void main(void)
{
    node *root = NULL;
    node *n = (node *)malloc(sizeof(node));
    int size, size1, num;
    int *l;
    scanf("%d", &num);
    while (1)
    {
        if (num == 1)
        {
            scanf("%d", &size);
            int *inorder = (int *)malloc(size * sizeof(int));
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &inorder[i]);
            }

            scanf("%d", &size1);
            int *postorder = (int *)malloc(size * sizeof(int));
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &postorder[i]);
            }
            n->value = postorder[size - 1];
            n->left_ptr = NULL;
            n->right_ptr = NULL;
            root = n;
            create(postorder, &root, size);
            menu1(root);
        }
        else if (num == 2)
        {
            int d, test;
            scanf("%d", &d);
            if (delete_node(root, root, d) == 0)
            {
                printPreorder(root);
            }
            printf("\n");
        }
        else if (num == -1)
        {
            exit(0);
        }
        scanf("%d", &num);
    }
}