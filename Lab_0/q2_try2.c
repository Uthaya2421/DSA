#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int final[20][20];
int size;

struct QNode
{
    int lvl;
    char *str;
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
};

struct QNode *newNode(int k, char *c)
{
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->lvl = k;
    temp->str = c;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q, char *c, int k)
{
    struct QNode *temp = newNode(k, c);

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue *q)
{
    if (q->front == NULL)
        return;

    struct QNode *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    printf("%s\n", temp->str);
    free(temp);
}

void check(int size, int board[size][size], int lvl)
{
    int c = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == final[i][j])
            {
                c++;
            }
        }
    }

    if (c == (size * size))
    {
        printf("%d", lvl);
        exit(0);
    }
}

void bfs(int size, int board[size][size], int lvl)
{
    int temp1, temp2;
    lvl++;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 0)
            {
                temp1 = i;
                temp2 = j;
            }
        }
    }

    if (temp1 - 1 >= 0)
    {
        // int new[size][size];
        int(*new)[size] = calloc(size, sizeof *new);
        int t;
        // int **new = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++)
        {
            // new[i] = (int *)malloc(size * sizeof(int));
            for (int j = 0; j < size; j++)
            {
                new[i][j] = board[i][j];
            }
        }
        t = new[temp1][temp2];
        new[temp1][temp2] = new[temp1 - 1][temp2];
        new[temp1 - 1][temp2] = t;

        check(size, new, lvl);
    }

    if (temp1 + 1 < size)
    {
        // int new[size][size];
        int t;
        // int **new = (int **)malloc(size * sizeof(int *));
        int(*new)[size] = calloc(size, sizeof *new);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                new[i][j] = board[i][j];
            }
        }
        t = new[temp1][temp2];
        new[temp1][temp2] = new[temp1 + 1][temp2];
        new[temp1 + 1][temp2] = t;
        check(size, new, lvl);
    }

    if (temp2 - 1 >= 0)
    {
        // int new[size][size];
        int t;
        // int **new = (int **)malloc(size * sizeof(int *));
        int(*new)[size] = calloc(size, sizeof *new);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                new[i][j] = board[i][j];
            }
        }
        t = new[temp1][temp2];
        new[temp1][temp2] = new[temp1][temp2 - 1];
        new[temp1][temp2 - 1] = t;
        check(size, new, lvl);
    }

    if (temp2 + 1 < size)
    {
        // int new[size][size];
        int t;
        // int **new = (int **)malloc(size * sizeof(int *));
        int(*new)[size] = calloc(size, sizeof *new);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                new[i][j] = board[i][j];
            }
        }
        t = new[temp1][temp2];
        new[temp1][temp2] = new[temp1][temp2 + 1];
        new[temp1][temp2 + 1] = t;
        check(size, new, lvl);
    }
}

int main()
{
    int size, temp1, temp2;
    scanf("%d", &size);
    int lvl;
    int board[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == size - 1 && j == size - 1)
            {
                final[i][j] = 0;
            }
            else
            {
                final[i][j] = count;
                count++;
            }
        }
    }
    lvl = 0;

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         printf("%d ", final[i][j]);
    //     }
    //     printf("\n");
    // }

    check(size, board, lvl);
    char c[200];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 && j == 0)
            {
                sprintf(c, "%d", board[i][j]);
                strcat(c, " ");
            }
            // strcpy(c, itoa(final[i][j]));
            else
            {
                char t[10];
                sprintf(t, "%d", board[i][j]);
                strcat(c, t);
                strcat(c, " ");
            }
        }
    }

    struct Queue *q = createQueue();
    enQueue(q, c, lvl);
    // deQueue(q);
    bfs(size, board, lvl);
}