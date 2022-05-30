#include <stdio.h>
#include <stdlib.h>

int *multiply(int A[], int B[], int m, int n)
{
    int *prod = (int *)malloc(sizeof(int) * (m + n - 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            prod[i + j] += A[i] * B[j];
    }

    for (int i = 0; i < m + n - 1; i++)
    {
        printf("%d ", prod[i]);
    }

    return prod;
}

int main(void)
{
    int order;
    // int *prod;
    scanf("%d", &order);
    int *a = (int *)malloc(sizeof(int) * (order + 1));
    int *b = (int *)malloc(sizeof(int) * (order + 1));

    for (int i = 0; i < order + 1; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < order + 1; i++)
    {
        scanf("%d", &b[i]);
    }

    int *prod = (int *)malloc(sizeof(int) * ((2 * order) + 1));

    for (int i = 0; i < 2 * order + 1; i++)
        prod[i] = 0;

    for (int i = 0; i < order + 1; i++)
    {
        for (int j = 0; j < order + 1; j++)
            prod[i + j] += a[i] * b[j];
    }

    for (int i = 0; i < 2 * order + 1; i++)
    
    {
        printf("%d ", prod[i]);
    }
}