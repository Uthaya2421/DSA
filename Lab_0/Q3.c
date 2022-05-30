#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;
    int temp;
    arr = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    temp = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }
    }
    printf("The largest number in the array is : %d", temp);
    return 0;
}