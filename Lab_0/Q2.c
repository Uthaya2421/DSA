#include <stdio.h>
#include <stdlib.h>
void main()
{

    int arr_1[4] = {1, 2, 3, 4};
    int arr_2[3] = {5, 6, 7};
    int *ad = (int *)malloc(7 * sizeof(int));
    for (int i = 0; i < 7; i++)
    {
        if (i < 4)
        {
            ad[i] = arr_1[i];
        }
        else
        {
            ad[i] = arr_2[i - 4];
        }
    }

    free(ad);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", ad[i]);
    }
}