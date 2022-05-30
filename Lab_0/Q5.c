#include <stdio.h>
#include <math.h>

int main(void)
{
    float x, i, frac;
    int integer, res = 1;
    scanf("%f %f", &x, &i);
    integer = (int)i;
    frac = i - integer;
    printf("%d\n", integer);
    if (integer > 0)
    {
        for (int j = 0; j < integer; j++)
        {
            res *= x;
        }
    }

    printf("result : %d\n", res);
}