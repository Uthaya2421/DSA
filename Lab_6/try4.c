#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_zero(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = 0;
    }
}

void disp(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int *DnC(int a[], int b[], int c[], int l)
{
    // disp(a, l + 1);
    // disp(b, l + 1);
    if (l == 1)
    {
        int U = (a[0] + a[1]) * (b[0] + b[1]);
        // printf("%d\n", U);
        int V = a[0] * b[0];
        // printf("%d\n", V);
        int W = a[1] * b[1];
        // printf("%d\n", W);
        int Z = U - V - W;
        // printf("%d\n", Z);

        c[0] = V;
        c[1] = Z;
        c[2] = W;
    }
    else
    {
        int mid;
        mid = l / 2;
        int A0[mid + 1], A1[mid + 1], B0[mid + 1], B1[mid + 1];
        memset(A0, 0, sizeof(A0));
        memset(A1, 0, sizeof(A0));
        memset(B0, 0, sizeof(A0));
        memset(B1, 0, sizeof(A0));

        for (int i = 0; i < l + 1; i++)
        {
            if (i < l - mid)
            {
                A0[i] = a[i];
            }
            else
            {
                A1[i - l + mid] = a[i];
            }
        }

        for (int i = 0; i < l + 1; i++)
        {
            if (i < l - mid)
            {
                B0[i] = b[i];
            }
            else
            {
                B1[i - l + mid] = b[i];
            }
        }

        int *X = (int *)malloc(sizeof(int) * (mid + 1));
        int *Y = (int *)malloc(sizeof(int) * (mid + 1));
        int *P = (int *)malloc(sizeof(int) * (2 * (mid) + 1));
        int *Q = (int *)malloc(sizeof(int) * (2 * (mid) + 1));
        int *R = (int *)malloc(sizeof(int) * (2 * (mid) + 1));
        int *S = (int *)malloc(sizeof(int) * (2 * (mid) + 1));

        DnC(A0, B0, P, mid);
        // disp(P, (2 * (mid) + 1));

        for (int i = 0; i < mid + 1; i++)
        {
            X[i] = A0[i] + A1[i];
            Y[i] = B0[i] + B1[i];
        }
        // printf("\n");
        // disp(X, mid + 1);
        // disp(Y, mid + 1);
        DnC(X, Y, Q, mid);
        // disp(Q, (2 * (mid) + 1));

        DnC(A1, B1, R, mid);
        // disp(R, (2 * (mid) + 1));

        for (int i = 0; i < 2 * (mid) + 1; i++)
        {
            S[i] = Q[i] - P[i] - R[i];
        }

        for (int i = 0; i < 2 * (mid) + 1; i++)
        {
            c[i] += P[i];
            c[i + l - mid] += S[i];
            c[i + (2 * (l - mid))] += R[i];
        }
    }
}

int main(void)
{
    int order;
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
    int c[(2 * (order) + 1)];
    fill_zero(&c, sizeof(c));

    DnC(a, b, c, order);
    disp(c, (2 * (order) + 1));
}