#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int count;
    int storage_capacity;
    int bookId;
    struct node *front, *rear, *prev, *next;
} node;

typedef struct Hash
{
    int capacity;
    node **array;
} Hash;

node *createNode(int bookId)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->bookId = bookId;
    temp->prev = temp->next = NULL;

    return temp;
}

node *createQueue(int storage_capacity)
{
    node *queue = (node *)malloc(sizeof(node));

    queue->count = 0;
    queue->front = queue->rear = NULL;

    queue->storage_capacity = storage_capacity;

    return queue;
}

Hash *createHash(int capacity)
{
    Hash *hash = (Hash *)malloc(sizeof(Hash));
    hash->capacity = capacity;
    hash->array = (node **)malloc(hash->capacity * sizeof(node *));

    for (int i = 0; i < hash->capacity; ++i)
        hash->array[i] = NULL;

    return hash;
}

int isFull(node *queue)
{
    if (queue->count == queue->storage_capacity)
        return 1;
    else
        return 0;
}

int isEmpty(node *queue)
{
    if (queue->rear == NULL)
        return 1;
    else
        return 0;
}

void deQueue(node *queue)
{
    if (isEmpty(queue))
        return;

    if (queue->front == queue->rear)
        queue->front = NULL;

    node *temp = queue->rear;
    queue->rear = queue->rear->prev;

    if (queue->rear)
        queue->rear->next = NULL;

    free(temp);

    queue->count--;
}

void Enqueue(node *queue, Hash *hash, int bookId)
{
    if (isFull(queue))
    {
        hash->array[queue->rear->bookId] = NULL;
        deQueue(queue);
    }

    node *temp = createNode(bookId);
    temp->next = queue->front;

    if (isEmpty(queue))
        queue->rear = queue->front = temp;
    else
    {
        queue->front->prev = temp;
        queue->front = temp;
    }

    hash->array[bookId] = temp;

    queue->count++;
}

void refBook(node *queue, Hash *hash, int bookId)
{
    node *reqBook = hash->array[bookId];

    if (reqBook == NULL)
        Enqueue(queue, hash, bookId);

    else if (reqBook != queue->front)
    {
        reqBook->prev->next = reqBook->next;
        if (reqBook->next)
            reqBook->next->prev = reqBook->prev;

        if (reqBook == queue->rear)
        {
            queue->rear = reqBook->prev;
            queue->rear->next = NULL;
        }

        reqBook->next = queue->front;
        reqBook->prev = NULL;

        reqBook->next->prev = reqBook;

        queue->front = reqBook;
    }
}

int main()
{
    int n, m, l;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &l);

    node *q = createQueue(m);

    Hash *hash = createHash(l + n);

    for (int i = 0; i < l; i++)
    {
        int t;
        scanf("%d", &t);
        refBook(q, hash, t);
        node *temp = q->rear;
        for (int i = 0; i < m; i++)
        {
            printf("%d ", temp->bookId);
            if (temp->prev == NULL)
            {
                break;
            }
            temp = temp->prev;
        }
        printf("\n");
    }
}