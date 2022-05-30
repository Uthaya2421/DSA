#include <stdio.h>
#include <stdlib.h>

int **a;

void dfs(int m, int n, int r, int c)
{
    a[r][c] = 2;
    if (r - 1 >= 0 && r - 1 < m && c - 1 >= 0 && c - 1 < n && a[r - 1][c - 1] == 0)
    {
        dfs(m, n, r - 1, c - 1);
    }
    if (r - 1 >= 0 && r - 1 < m && c >= 0 && c < n && a[r - 1][c] == 0)
    {
        dfs(m, n, r - 1, c);
    }
    if (r - 1 >= 0 && r - 1 < m && c + 1 >= 0 && c + 1 < n && a[r - 1][c + 1] == 0)
    {
        dfs(m, n, r - 1, c + 1);
    }
    if (r >= 0 && r < m && c - 1 >= 0 && c - 1 < n && a[r][c - 1] == 0)
    {
        dfs(m, n, r, c - 1);
    }
    if (r >= 0 && r < m && c + 1 >= 0 && c + 1 < n && a[r][c + 1] == 0)
    {
        dfs(m, n, r, c + 1);
    }
    if (r + 1 >= 0 && r + 1 < m && c - 1 >= 0 && c - 1 < n && a[r + 1][c - 1] == 0)
    {
        dfs(m, n, r + 1, c - 1);
    }
    if (r + 1 >= 0 && r + 1 < m && c >= 0 && c < n && a[r + 1][c] == 0)
    {
        dfs(m, n, r + 1, c);
    }
    if (r + 1 >= 0 && r + 1 < m && c + 1 >= 0 && c + 1 < n && a[r + 1][c + 1] == 0)
    {
        dfs(m, n, r + 1, c + 1);
    }
}

void check_boundary(int m, int n)
{
    int temp[m][n];

    // for (int i = 0; i < m; i++)
    // {
    //     // int *c = (int*)malloc(n*sizeof(int));
    //     for (int j = 0; j < n; j++)
    //     {
    //         temp[i][j] = 0;
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == 0)
        {
            dfs(m, n, 0, i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[m][i] == 0)
        {
            dfs(m, n, m, i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
        {
            dfs(m, n, i, 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][n] == 0)
        {
            dfs(m, n, i, n);
        }
    }
}

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    a = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");

    check_boundary(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}