#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void disp(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int *DnC(int a[], int b[], int l)
{
    disp(a, l + 1);
    disp(b, l + 1);
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

        int *t = (int *)malloc(sizeof(int) * 3);
        t[0] = V;
        t[1] = Z;
        t[2] = W;
        return t;
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

        P = DnC(A0, B0, mid);
        disp(P, (2 * (mid) + 1));

        for (int i = 0; i < mid + 1; i++)
        {
            X[i] = A0[i] + A1[i];
            Y[i] = B0[i] + B1[i];
        }
        printf("\n");
        disp(X, mid + 1);
        disp(Y, mid + 1);
        Q = DnC(X, Y, mid);
        disp(Q, (2 * (mid) + 1));

        R = DnC(A1, B1, mid);
        disp(R, (2 * (mid) + 1));

        for (int i = 0; i < 2 * (mid) + 1; i++)
        {
            S[i] = Q[i] - P[i] - R[i];
        }

        int d[(2 * (l) + 1)];
        memset(d, 0, sizeof(d));
        disp(d, (2 * (l) + 1));

        for (int i = 0; i < 2 * (mid) + 1; i++)
        {
            d[i] += P[i];
            d[i + 2] += S[i];
            d[i + 4] += R[i];
        }
        disp(d, (2 * (l) + 1));
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

    DnC(a, b, order);
}