#include <stdio.h>
#include <stdlib.h>
int *linear_sort(int *arr, int n);

void main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *sorted_arr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sorted_arr = linear_sort(arr, n);

    printf("array after sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sorted_arr[i]);
    }
}

int *linear_sort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
