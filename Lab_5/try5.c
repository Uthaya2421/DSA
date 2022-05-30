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

int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left_ptr);
        int rheight = height(node->right_ptr);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(node *root, int level, int *p, int *leaf)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        // printf("%d ", root->value);
        if (root->left_ptr == NULL && root->right_ptr == NULL)
        {
            *leaf += 1;
        }
        *p += 1;
    }

    else if (level > 1)
    {
        printCurrentLevel(root->left_ptr, level - 1, p, leaf);
        printCurrentLevel(root->right_ptr, level - 1, p, leaf);
    }
}

void printLevelOrder(node *root)
{
    int l[100];
    int ind = 0;
    int h = height(root);
    int count = 0;
    int *p = &count;
    int leaf = 0;

    // printf("%d \n", h);
    int i;
    for (i = 1; i <= h; i++)
    {
        *p = 0;
        l[ind] = i - 1;
        // printf("i - %d ", l[ind]);
        ind++;
        printCurrentLevel(root, i, p, &leaf);
        l[ind] = *p;
        // printf("v - %d ", l[ind]);
        ind++;
    }
    printf("%d\n", leaf);
    printf("%d\n", l[ind - 2] + 1);
    for (int i = 0; i < ind; i += 2)
    {
        printf("%d %d\n", l[i], l[i + 1]);
    }
}

node *minValueNode(node *node)
{
    struct node *current;
    current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left_ptr != NULL)
        current = current->left_ptr;

    return current;
}

/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
node *deleteNode(node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->value)
        root->left_ptr = deleteNode(root->left_ptr, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->value)
        root->right_ptr = deleteNode(root->right_ptr, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left_ptr == NULL)
        {
            node *temp = root->right_ptr;
            free(root);
            return temp;
        }
        else if (root->right_ptr == NULL)
        {
            node *temp = root->left_ptr;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node *temp = minValueNode(root->right_ptr);

        // Copy the inorder
        // successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right_ptr = deleteNode(root->right_ptr, temp->value);
    }
    return root;
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->value);

    /* then recur on left subtree */
    printPreorder(node->left_ptr);

    /* now recur on right subtree */
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
            printLevelOrder(root);
        }
        else if (num == 2)
        {
            int d;
            scanf("%d", d);
            deleteNode(root, d);
            printPreorder(root);
        }
        else if (num == -1)
        {
            exit(0);
        }
        scanf("%d", &num);
    }
}