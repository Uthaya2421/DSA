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

void printInorder(node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left_ptr);

    /* then print the data of node */
    printf("%d ", node->value);

    /* now recur on right child */
    printInorder(node->right_ptr);
}

int height(node *head)
{
    int count = 0;
    node *tmp = head;
    while (tmp->left_ptr != NULL && tmp->right_ptr == NULL)
    {
        if (tmp->value !=)
        {
            break;
        }
        else if (tmp->value > low)
        {
        }
    }
}

void main(void)
{
    node *root = NULL;
    node *n = (node *)malloc(sizeof(node));
    int size, size1, h;
    // int inorder[] = {7 ,10 ,13, 15, 19};
    // int postorder[] = {10, 7, 19, 15, 13};
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
    printInorder(root);
    h = height(root, inorder, size);
}