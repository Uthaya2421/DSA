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
    char *camera;
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
    return N->height;
}

node *newNode(int id, char *name, int price, char *company, char *camera, char *colour, int RAM, int battery, int removable_battery)
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
    char *temp_camera = (char *)malloc(100);
    strcpy(temp_camera, camera);
    n->camera = temp_camera;
    char *temp_colour = (char *)malloc(100);
    strcpy(temp_colour, colour);
    n->colour = temp_colour;
    n->RAM = RAM;
    n->battery = battery;
    n->removable_battery = removable_battery;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    // printf("%d", n->id);
    return (n);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *insert(node *node, int id, char *name, int price, char *company, char *camera, char *colour, int RAM, int battery, int removable_battery)
{
    if (node == NULL)
        return (newNode(id, name, price, company, camera, colour, RAM, battery, removable_battery));

    if (price < node->price)
        node->left = insert(node->left, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else if (price > node->price)
        node->right = insert(node->right, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

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

node *insert_2(node *node, int id, char *name, int price, char *company, char *camera, char *colour, int RAM, int battery, int removable_battery)
{
    if (node == NULL)
        return (newNode(id, name, price, company, camera, colour, RAM, battery, removable_battery));

    if (strcmp(name, node->name) < 0)
        node->left = insert_2(node->left, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else if (strcmp(name, node->name) > 0)
        node->right = insert_2(node->right, id, name, price, company, camera, colour, RAM, battery, removable_battery);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

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

char *search(node *head, int val, int p)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->price == val)
        {
            if (p == 1)
                printf("ID: %d, %s, %d, %s, %s, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);

            return tmp->name;
        }
        else if (tmp->price < val)
        {
            tmp = tmp->right;
        }
        else if (tmp->price > val)
        {
            tmp = tmp->left;
        }
    }
    if (p == 1)
        printf("Not Found\n");
}

int search_2(node *head, char *val, int p)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        // printf("%s\n", val);
        if (strcmp(tmp->name, val) == 0)
        {
            if (p == 1)
                printf("ID: %d, %s, %d, %s, %s, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);
            return tmp->price;
        }
        else if (strcmp(val, tmp->name) > 0)
        {
            tmp = tmp->right;
        }
        else if (strcmp(val, tmp->name) < 0)
        {
            tmp = tmp->left;
        }
    }
    if (p == 1)
        printf("Not Found\n");
}
node *minValueNode(node *nod)
{
    node *current = nod;

    while (current->left != NULL)
        current = current->left;

    return current;
}

node *deleteNode(node *root, int price, int tt)
{

    if (root == NULL)
    {
        printf("Not Found\n");
        return root;
    }

    if (price < root->price)
        root->left = deleteNode(root->left, price, tt);

    else if (price > root->price)
        root->right = deleteNode(root->right, price, tt);

    else
    {
        if (tt == 0)
        {
            printf("Deleted ID: %d\n", root->id);
        }

        if ((root->left == NULL) || (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            tt++;
            node *temp = minValueNode(root->right);

            root->id = temp->id;
            root->name = temp->name;
            root->price = temp->price;
            root->company = temp->company;
            root->camera = temp->camera;
            root->colour = temp->colour;
            root->RAM = temp->RAM;
            root->battery = temp->battery;
            root-> removable_battery = temp->removable_battery;

            root->right = deleteNode(root->right, temp->price, tt);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node *deleteNode_2(node *root, char *name, int t)
{

    if (root == NULL)
    {
        // printf("Not Found\n");
        return root;
    }

    if (strcmp(name, root->name) < 0)
        root->left = deleteNode_2(root->left, name, t);

    else if (strcmp(name, root->name) > 0)
        root->right = deleteNode_2(root->right, name, t);

    else
    {
        // if (t == 0)
        // {
        //     printf("Deleted ID: %d\n", root->id);
        // }
        if ((root->left == NULL) || (root->right == NULL))
        {
            node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            t++;
            node *temp = minValueNode(root->right);

            root->id = temp->id;
            root->name = temp->name;
            root->price = temp->price;
            root->company = temp->company;
            root->camera = temp->camera;
            root->colour = temp->colour;
            root->RAM = temp->RAM;
            root->battery = temp->battery;
            root-> removable_battery = temp->removable_battery;

            root->right = deleteNode_2(root->right, temp->name, t);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void Range(node *root, int k1, int k2)
{

    if (NULL == root)
        return;

    if (k1 < root->price)
        Range(root->left, k1, k2);

    if (k1 <= root->price && k2 >= root->price)
        printf("ID: %d, %s, %d, %s, %s, %s, %d, %d, %d\n", root->id, root->name, root->price, root->company, root->camera, root->colour, root->RAM, root->battery, root->removable_battery);

    Range(root->right, k1, k2);
}
void preOrder_p(node *tmp)
{
    if (tmp != NULL)
    {
        printf("ID: %d, %s, %d, %s, %s, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);
        preOrder_p(tmp->left);
        preOrder_p(tmp->right);
    }
}

void preOrder(node *tmp)
{
    if (tmp != NULL)
    {
        printf("ID: %d, %s, %d, %s, %s, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);
        preOrder(tmp->left);
        preOrder(tmp->right);
    }
}

int main()

{
    node *head = NULL;
    node *head_2 = NULL;
    int id = 0;

    while (1)
    {
        char s[10];
        scanf("%s ", &s);

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
            char *camera = token_list[3];
            char *colour = token_list[4];
            int RAM = atoi(token_list[5]);
            int battery = atoi(token_list[6]);
            int removable_battery = atoi(token_list[7]);
            head = insert(head, id, name, price, company, camera, colour, RAM, battery, removable_battery);
            head_2 = insert_2(head_2, id, name, price, company, camera, colour, RAM, battery, removable_battery);
            printf("ID: %d\n", id);
            // preOrder_p(head);
            // printf("-------------------------------------------\n");
            // preOrder(head_2);
        }
        else if (strcmp(s, "QP") == 0)
        {
            int val, p = 1;
            scanf("%d", &val);
            search(head, val, p);
        }
        else if (strcmp(s, "QN") == 0)
        {
            int p = 1;
            char n[100];
            scanf("%[^\n]s", &n);
            search_2(head_2, n, p);
        }
        else if (strcmp(s, "DP") == 0)
        {
            int val;
            int tt = 0;
            // int t = 0;
            scanf("%d", &val);
            char *name_t;
            name_t = search(head, val, 0);
            head_2 = deleteNode_2(head_2, name_t, 0);
            head = deleteNode(head, val, tt);
            // preOrder_p(head);
            // printf("-------------------------------------------\n");
            // preOrder(head_2);
        }
        else if (strcmp(s, "DN") == 0)
        {
            // preOrder(head_2);
            int t = 0;
            // int tt = 0;
            char n[100];
            int price_t;
            scanf("%[^\n]s", &n);
            price_t = search_2(head_2, n, 0);
            // printf("%d\n", price_t);
            head = deleteNode(head, price_t, 0);
            head_2 = deleteNode_2(head_2, n, t);
            // preOrder_p(head);
            // printf("-------------------------------------------\n");
            // preOrder(head_2);
        }
        else if (strcmp(s, "R") == 0)
        {
            int k1, k2;
            scanf("%d %d", &k1, &k2);
            Range(head, k1, k2);
        }
        else if (strcmp(s, "T") == 0)
        {
            break;
        }
    }
}
