#include <stdio.h>
#include <stdlib.h>

int final[20][20];

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

    bfs(size, board, lvl);
}