#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    int id;
    char *name;
    int price;
    char *company;
    float camera;
    char *colour;
    int RAM;
    int battery;
    int removable_battery;
    int height;
    struct node *left;
    struct node *right;
} node;

void disp(node *root)
{
    for (node *tmp = root; tmp != NULL; tmp = tmp->left)
    {
        printf("%s\n", tmp->name);
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return 1 + max(height(N->left), height(N->right));
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
node *newNode(int id, char *name, int price, char *company, float camera, char *colour, int RAM, int battery, int removable_battery)
{
    node *n = (node *)malloc(sizeof(node));
    n->id = id;
    char *temp_name = (char *)malloc(100);
    strcpy(temp_name, name);
    n->name = temp_name;
    n->price = price;
    char *temp_company = (char *)malloc(100);
    strcpy(temp_company, company);
    n->company = temp_company;
    n->camera = camera;
    char *temp_colour = (char *)malloc(100);
    strcpy(temp_colour, colour);
    n->colour = temp_colour;
    n->RAM = RAM;
    n->battery = battery;
    n->removable_battery = removable_battery;
    n->left = NULL;
    n->right = NULL;
    n->height = 0; // new node is initially added at leaf
    // printf("%d", n->id);
    return (n);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = height(y);
    x->height = height(x);

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = height(x);
    y->height = height(y);

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *insert(node *node, int id, char *name, int price, char *company, float camera, char *colour, int RAM, int battery, int removable_battery)
{
    if (node == NULL)
        return (newNode(id, name, price, company, camera, colour, RAM, battery, removable_battery));

    if (price < node->price)
        node->left = insert(node->left, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else if (price > node->price)
        node->right = insert(node->right, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else
        return node;

    node->height = height(node);

    int balance = getBalance(node);

    if (balance > 1 && price < node->left->price)
        return rightRotate(node);

    if (balance < -1 && price > node->right->price)
        return leftRotate(node);

    if (balance > 1 && price > node->left->price)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && price < node->right->price)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

node *insert_2(node *node, int id, char *name, int price, char *company, float camera, char *colour, int RAM, int battery, int removable_battery)
{
    if (node == NULL)
        return (newNode(id, name, price, company, camera, colour, RAM, battery, removable_battery));

    if (strcmp(name, node->name) < 0)
        node->left = insert_2(node->left, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else if (strcmp(name, node->name) > 0)
        node->right = insert_2(node->right, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else
        return node;

    node->height = height(node);

    int balance = getBalance(node);

    if (balance > 1 && strcmp(name, node->left->name) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(name, node->right->name) > 0)
        return leftRotate(node);

    if (balance > 1 && strcmp(name, node->left->name) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(name, node->right->name) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void search(node *head, int val)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->price == val)
        {
            printf("ID: %d, %s, %d, %s, %f, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);
            return;
        }
        else if (tmp->price < val)
        {
            tmp = tmp->right;
        }
        else
        {
            tmp = tmp->left;
        }
    }
    printf("Not Found\n");
}

void search_2(node *head, char *val)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        // printf("%s\n", val);
        if (strcmp(tmp->name, val) == 0)
        {
            printf("ID: %d, %s, %d, %s, %f, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);
            return;
        }
        else if (strcmp(tmp->name, val) > 0)
        {
            tmp = tmp->right;
        }
        else
        {
            tmp = tmp->left;
        }
    }
    printf("Not Found\n");
}
node *minValueNode(node *nod)
{
    node *current = nod;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node *deleteNode(node *root, int price, int tt)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
    {
        printf("Not Found\n");
        return root;
    }

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (price < root->price)
        root->left = deleteNode(root->left, price, tt);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if (price > root->price)
        root->right = deleteNode(root->right, price, tt);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        if (tt == 0)
        {
            printf("Deleted ID: %d\n", root->id);
        }
        // node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            tt++;
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->price = temp->price;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->price, tt);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node *deleteNode_2(node *root, char *name, int t)
{

    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
    {
        printf("Not Found\n");
        return root;
    }

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (strcmp(name, root->name) < 0)
        root->left = deleteNode_2(root->left, name, t);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if (strcmp(name, root->name) > 0)
        root->right = deleteNode_2(root->right, name, t);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        if (t == 0)
        {
            printf("Deleted ID: %d\n", root->id);
        }
        // node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child

            free(temp);
        }
        else
        {
            t++;
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->name = temp->name;

            // Delete the inorder successor
            root->right = deleteNode_2(root->right, temp->name, t);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()

{
    node *head = NULL;
    node *head_2 = NULL;
    int id = 0;

    while (1)
    {
        char *s;
        scanf("%s ", s);

        if (strcmp(s, "A") == 0)
        {
            id++;
            char str[100];

            scanf("%[^\n]s", str);
            // char input_string[] = "Nokia 6.2, 12000, Nokia, 24, Grey, 8, 3000, 0";
            char token_list[20][20];
            char *token = strtok(str, ",");
            int num_tokens = 0;
            while (token != NULL)
            {
                strcpy(token_list[num_tokens], token);
                num_tokens++;
                token = strtok(NULL, ", ");
            }

            char *name = token_list[0];
            int price = atoi(token_list[1]);
            char *company = token_list[2];
            float camera = atof(token_list[3]);
            char *colour = token_list[4];
            int RAM = atoi(token_list[5]);
            int battery = atoi(token_list[6]);
            int removable_battery = atoi(token_list[7]);
            head = insert(head, id, name, price, company, camera, colour, RAM, battery, removable_battery);
            head_2 = insert_2(head_2, id, name, price, company, camera, colour, RAM, battery, removable_battery);
            printf("ID: %d\n", id);
            // node *n = (node *)malloc(sizeof(node));
            // n->name = token_list[0];
            // n->price = atoi(token_list[1]);
            // n->company = token_list[2];
            // n->camera = atof(token_list[3]);
            // n->colour = token_list[4];
            // n->RAM = atoi(token_list[5]);
            // n->battery = atoi(token_list[6]);
            // n->removable_battery = atoi(token_list[7]);
            // n->left = NULL;
            // n->right = NULL;
            // head = n;
            // for (int i = 0; i < num_tokens; i++)
            // {
            //     printf("%s ", token_list[i]);
            // }

            // printf("\n");
            // printf("%s", head->company);
        }
        else if (strcmp(s, "QP") == 0)
        {
            int val;
            scanf("%d", &val);
            search(head, val);
        }
        else if (strcmp(s, "QN") == 0)
        {
            char n[100];
            scanf("%[^\n]s", &n);
            search_2(head_2, n);
        }
        else if (strcmp(s, "DP") == 0)
        {
            int val;
            int tt = 0;
            scanf("%d", &val);
            head = deleteNode(head, val, tt);
        }
        else if (strcmp(s, "DN") == 0)
        {
            disp(head_2);
            int t = 0;
            char n[100];
            scanf("%[^\n]s", &n);
            head_2 = deleteNode_2(head_2, n, t);
            disp(head_2);
        }
        else if (strcmp(s, "T") == 0)
        {
            break;
        }
    }
    // disp(head);
    // disp(head_2);
}
