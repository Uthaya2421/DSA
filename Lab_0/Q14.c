#include <stdio.h>

int fact(int n)
{
    int res = 1;
    if (n > 1)
    {
        res = n * fact(n - 1);
    }
    return res;
}

void main()
{
    int n, f;
    scanf("%d", &n);
    if (n > 1)
    {
        printf("Factorial : %d", fact(n));
    }
    else
    {
        printf("Factorial : 1");
    }
}