#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int bookno;
    struct Node *prev, *next;
} node;

typedef struct Queue
{
    int filled_nodes;
    int total_space;
    node *front, *rear;
} queue;

node *newnode(int book)
{
    node *a = (node *)malloc(sizeof(node));
    a->bookno = book;
    a->prev = NULL;
    a->next = NULL;

    return a;
}

queue *create_q(int m)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->filled_nodes = 0;
    q->total_space = m;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

int QueueFullCheck(queue *q)
{
    if (q->filled_nodes == q->total_space)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int QueueEmptyCheck(queue *q)
{
    if (q->rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void NpresentInQueueCheck(queue *q, int book)
{
    node *temp = q->front;
    while (temp != NULL)
    {
        if (temp->bookno == book)
        {
            node *temp1 = temp->next;
            node *temp2 = temp->prev;

            if (temp1 == NULL)
            {
                if (temp2 == NULL)
                {
                    q->front = NULL;
                    q->rear = NULL;
                    break;
                }
                else
                {
                    q->rear = temp2;
                    break;
                }
            }
            else
            {
                if (temp2 == NULL)
                {
                    q->front = temp1;
                    break;
                }
                else
                {
                    temp1->prev = temp2;
                    temp2->next = temp1;

                    temp = temp1;
                }
            }
        }

        else
        {
            temp = temp->next;
        }
    }
}

void enqueue(queue *q, int book)
{
    node *New = newnode(book);
    NpresentInQueueCheck(q, book);
    if (QueueFullCheck(q))
    {
        New->prev = q->rear;
        New->next = NULL;

        node *temp1 = q->rear;
        temp1->next = New;
        q->rear = New;

        node *temp2 = q->front;
        node *temp3 = temp2->next;
        temp3->prev = NULL;
        q->front = temp3;
    }

    else
    {
        if (QueueEmptyCheck(q))
        {
            q->rear = New;
            q->front = New;
        }

        else
        {
            node *temp = q->rear;
            q->rear = New;
            temp->next = New;
            New->prev = temp;
        }

        q->filled_nodes = q->filled_nodes + 1;
    }
}

void main()
{
    int N, m;
    int a;
    int arr[100];

    scanf("%d", &N);

    scanf("%d", &m);

    do
    {
        scanf("%d", &arr[a++]);
    } while (getchar() != '\n');

    queue *myQueue = create_q(m);
    for (int i = 1; i < arr[0]; ++i)
    {
        enqueue(myQueue, arr[i]);

        node *temp = myQueue->front;
        while (temp != NULL)
        {
            int b = temp->bookno;
            printf("%d ", b);
            temp->next;
        }

        printf("\n");
    }
}
