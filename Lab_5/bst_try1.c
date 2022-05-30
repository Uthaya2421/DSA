#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left_ptr;
    struct node *right_ptr;
} node;

void main(void)
{
    node *root = NULL;
    node *n = (node *)malloc(sizeof(node));
    int size1, size;
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
    node *temp = root;
    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (postorder[i] < postorder[i + 1])
            {
                n = (node *)malloc(sizeof(node));
                n->value = postorder[i];
                n->left_ptr = NULL;
                n->right_ptr = NULL;
                temp->left_ptr = n;
                temp = temp->left_ptr;
            }
            else
            {
                n = (node *)malloc(sizeof(node));
                n->value = postorder[i];
                n->left_ptr = NULL;
                n->right_ptr = NULL;
                temp->right_ptr = n;
                temp = temp->right_ptr;
            }
        }
    }
}