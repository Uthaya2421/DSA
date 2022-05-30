#include <stdio.h>
#include <string.h>

int main()
{
    int final[3][3], n[3][3];
    int count = 1;

    char c[100];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 2 && j == 2)
            {
                final[i][j] = 0;
            }
            else
            {
                final[i][j] = count;
                count++;
            }
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {

    //         printf("%d", final[i][j]);
    //     }
    // }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
            {
                sprintf(c, "%d", final[i][j]);
                strcat(c, " ");
            }
            // strcpy(c, itoa(final[i][j]));
            else
            {
                char t[10];
                sprintf(t, "%d", final[i][j]);
                strcat(c, t);
                strcat(c, " ");
            }
        }
    }
    char newString[100][100];
    int k, ctr;

    k = 0;
    ctr = 0;
    for (int i = 0; i <= (strlen(c)); i++)
    {
        if (c[i] == ' ' || c[i] == '\0')
        {
            newString[ctr][k] = '\0';
            ctr++;
            k = 0;
        }
        else
        {
            newString[ctr][k] = c[i];
            k++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        }
    }

    printf("%s", c);
}