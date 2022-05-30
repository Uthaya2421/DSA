#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left_ptr;
    struct node *right_ptr;
} node;

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

int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lheight = height(node->left_ptr);
        int rheight = height(node->right_ptr);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void CurrentLevel(node *root, int level, int *p, int *leaf)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {

        if (root->left_ptr == NULL && root->right_ptr == NULL)
        {
            *leaf += 1;
        }
        *p += 1;
    }

    else if (level > 1)
    {
        CurrentLevel(root->left_ptr, level - 1, p, leaf);
        CurrentLevel(root->right_ptr, level - 1, p, leaf);
    }
}

void printMenu1(node *root)
{
    int l[100];
    int ind = 0;
    int h = height(root);
    int count = 0;
    int *p = &count;
    int leaf = 0;

    int i;
    for (i = 1; i <= h; i++)
    {
        *p = 0;
        l[ind] = i - 1;

        ind++;
        CurrentLevel(root, i, p, &leaf);
        l[ind] = *p;

        ind++;
    }
    printf("%d\n", leaf);
    printf("%d\n", l[ind - 2] + 1);
    for (int i = 0; i < ind; i += 2)
    {
        printf("%d %d\n", l[i], l[i + 1]);
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
        while (root->left_ptr != NULL)
        {
            if (root->left_ptr->right_ptr == NULL && root->left_ptr->left_ptr == NULL)
            {
                tmp = root->left_ptr;
                root->left_ptr = NULL;
                return tmp;
            }
            root = root->left_ptr;
        }
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

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->value);

    printPreorder(node->left_ptr);

    printPreorder(node->right_ptr);
}

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
            printMenu1(root);
        }
        else if (num == 2)
        {
            int d, test;
            scanf("%d", &d);

            if (delete_node(root, root, d) == 0)
                printPreorder(root);
            printf("\n");
        }
        else if (num == -1)
        {
            exit(0);
        }
        scanf("%d", &num);
    }
}