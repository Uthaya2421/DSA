#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int parent[20];

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int *dijkstra(int V, int graph[V][V], int src, int *dist, char (*ind)[10])
{
    dist = (int *)malloc(sizeof(int) * V);

    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
    parent[src] = -1;
    // printf("%s ", ind[0]);

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        // printf("%s ", ind[u]);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                // printf("%s ", ind[u]);
            }
    }

    return dist;
}

void print(int u, int a, char (*ind)[10])
{
    int arr[a];
    for (int j = 0; j < a; j++)
    {
        arr[j] = -1;
    }
    int i = 0;
    while (u != -1)
    {
        arr[i] = u;
        u = parent[u];
        i++;
    }

    for (int j = a - 1; j > -1; j--)
    {
        if (arr[j] != -1)
            printf("%s ", ind[arr[j]]);
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    int graph[a][a];

    char *str1 = (char *)malloc(100);
    char newString[10][10];
    char ind[a][10];

    int *dist;
    int k, ctr, count, temp1, temp2;
    int indx = 0;
    char input[10];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            graph[i][j] = 0;
        }
    }

    gets(str1);
    for (int z = 0; z < a; z++)
    {
        gets(str1);

        k = 0;
        ctr = 0;
        for (int i = 0; i <= (strlen(str1)); i++)
        {
            if (str1[i] == ' ' || str1[i] == '\0')
            {
                newString[ctr][k] = '\0';
                ctr++;
                k = 0;
            }
            else
            {
                newString[ctr][k] = str1[i];
                k++;
            }
        }
        for (int u = 0; u < a; u++)
        {
            count = 0;
            if (strcmp(newString[0], ind[u]) == 0)
            {
                count = 1;
                break;
            }
        }
        if (count == 0)
        {
            strcpy(ind[indx], newString[0]);
            indx++;
        }

        for (int u = 0; u < a; u++)
        {
            count = 0;
            if (strcmp(newString[1], ind[u]) == 0)
            {
                count = 1;
                break;
            }
        }

        if (count == 0)
        {
            strcpy(ind[indx], newString[1]);
            indx++;
        }

        for (int u = 0; u < a; u++)
        {
            if (strcmp(newString[0], ind[u]) == 0)
            {
                temp1 = u;
            }

            if (strcmp(newString[1], ind[u]) == 0)
            {
                temp2 = u;
            }
        }
        graph[temp1][temp2] = atoi(newString[2]);
        graph[temp2][temp1] = atoi(newString[2]);
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    dist = dijkstra(a, graph, 0, dist, ind);
    int arr[a];

    while (1)
    {
        gets(input);
        if (strcmp("T", input) == 0)
        {
            exit(0);
        }
        else
        {
            for (int u = 0; u < a; u++)
            {
                if (strcmp(input, ind[u]) == 0)
                {
                    printf("%d ", dist[u]);
                    print(u, a, ind);

                    printf("\n");
                }
            }
        }
    }

    return 0;
}