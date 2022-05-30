#include <stdio.h>
#include <stdlib.h>

int a[50][50];

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{

    return stack->array[stack->top--];
}

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
    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == 0)
        {
            dfs(m, n, 0, i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[m - 1][i] == 0)
        {
            dfs(m, n, m - 1, i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i][0] == 0)
        {
            dfs(m, n, i, 0);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i][n - 1] == 0)
        {
            dfs(m, n, i, n - 1);
        }
    }
}

void func(struct Stack *stack1, struct Stack *stack2, struct Stack *stack3, int m, int n)
{
    int r, c;
    while (isEmpty(stack1) != 1 || isEmpty(stack2) != 1)
    {
        if (isEmpty(stack1) != 1)
        {
            while (isEmpty(stack3) != 1)
            {
                pop(stack3);
            }

            while (isEmpty(stack1) != 1)
            {
                c = pop(stack1);
                r = pop(stack1);
                push(stack3, r);
                push(stack3, c);

                a[r][c] = 3;

                if (r - 1 >= 0 && r - 1 < m && c - 1 >= 0 && c - 1 < n && a[r - 1][c - 1] == 0)
                {
                    push(stack2, r - 1);
                    push(stack2, c - 1);
                    a[r - 1][c - 1] = 2;
                }
                if (r - 1 >= 0 && r - 1 < m && c >= 0 && c < n && a[r - 1][c] == 0)
                {
                    push(stack2, r - 1);
                    push(stack2, c);
                    a[r - 1][c] = 2;
                }
                if (r - 1 >= 0 && r - 1 < m && c + 1 >= 0 && c + 1 < n && a[r - 1][c + 1] == 0)
                {
                    push(stack2, r - 1);
                    push(stack2, c + 1);
                    a[r - 1][c + 1] = 2;
                }
                if (r >= 0 && r < m && c - 1 >= 0 && c - 1 < n && a[r][c - 1] == 0)
                {
                    push(stack2, r);
                    push(stack2, c - 1);
                    a[r][c - 1] = 2;
                }
                if (r >= 0 && r < m && c + 1 >= 0 && c + 1 < n && a[r][c + 1] == 0)
                {
                    push(stack2, r);
                    push(stack2, c + 1);
                    a[r][c + 1] = 2;
                }
                if (r + 1 >= 0 && r + 1 < m && c - 1 >= 0 && c - 1 < n && a[r + 1][c - 1] == 0)
                {
                    push(stack2, r + 1);
                    push(stack2, c - 1);
                    a[r + 1][c - 1] = 2;
                }
                if (r + 1 >= 0 && r + 1 < m && c >= 0 && c < n && a[r + 1][c] == 0)
                {
                    push(stack2, r + 1);
                    push(stack2, c);
                    a[r + 1][c] = 2;
                }
                if (r + 1 >= 0 && r + 1 < m && c + 1 >= 0 && c + 1 < n && a[r + 1][c + 1] == 0)
                {
                    push(stack2, r + 1);
                    push(stack2, c + 1);
                    a[r + 1][c + 1] = 2;
                }
            }
        }

        else if (isEmpty(stack2) != 1)
        {
            while (isEmpty(stack3) != 1)
            {
                pop(stack3);
            }

            while (isEmpty(stack2) != 1)
            {
                c = pop(stack2);
                r = pop(stack2);
                push(stack3, r);
                push(stack3, c);

                a[r][c] = 3;

                if (r - 1 >= 0 && r - 1 < m && c - 1 >= 0 && c - 1 < n && a[r - 1][c - 1] == 0)
                {
                    push(stack1, r - 1);
                    push(stack1, c - 1);
                    a[r - 1][c - 1] = 2;
                }
                if (r - 1 >= 0 && r - 1 < m && c >= 0 && c < n && a[r - 1][c] == 0)
                {
                    push(stack1, r - 1);
                    push(stack1, c);
                    a[r - 1][c] = 2;
                }
                if (r - 1 >= 0 && r - 1 < m && c + 1 >= 0 && c + 1 < n && a[r - 1][c + 1] == 0)
                {
                    push(stack1, r - 1);
                    push(stack1, c + 1);
                    a[r - 1][c + 1] = 2;
                }
                if (r >= 0 && r < m && c - 1 >= 0 && c - 1 < n && a[r][c - 1] == 0)
                {
                    push(stack1, r);
                    push(stack1, c - 1);
                    a[r][c - 1] = 2;
                }
                if (r >= 0 && r < m && c + 1 >= 0 && c + 1 < n && a[r][c + 1] == 0)
                {
                    push(stack1, r);
                    push(stack1, c + 1);
                    a[r][c + 1] = 2;
                }
                if (r + 1 >= 0 && r + 1 < m && c - 1 >= 0 && c - 1 < n && a[r + 1][c - 1] == 0)
                {
                    push(stack1, r + 1);
                    push(stack1, c - 1);
                    a[r + 1][c - 1] = 2;
                }
                if (r + 1 >= 0 && r + 1 < m && c >= 0 && c < n && a[r + 1][c] == 0)
                {
                    push(stack1, r + 1);
                    push(stack1, c);
                    a[r + 1][c] = 2;
                }
                if (r + 1 >= 0 && r + 1 < m && c + 1 >= 0 && c + 1 < n && a[r + 1][c + 1] == 0)
                {
                    push(stack1, r + 1);
                    push(stack1, c + 1);
                    a[r + 1][c + 1] = 2;
                }
            }
        }
    }

    int i, j;
    while (isEmpty(stack3) != 1)
    {
        j = pop(stack3);
        i = pop(stack3);
        printf("%d %d\n", i, j);
    }
}

void max_depth(int m, int n)
{
    struct Stack *stack1 = createStack(100);
    struct Stack *stack2 = createStack(100);
    struct Stack *stack3 = createStack(100);

    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == 0)
        {
            push(stack1, 0);
            push(stack1, i);
            a[0][i] = 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[m - 1][i] == 0)
        {
            push(stack1, m - 1);
            push(stack1, i);
            a[m - 1][i] = 2;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i][0] == 0)
        {
            push(stack1, i);
            push(stack1, 0);
            a[i][0] = 2;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i][n - 1] == 0)
        {
            push(stack1, 1);
            push(stack1, n - 1);
            a[i][n - 1] = 2;
        }
    }

    if (isEmpty(stack1))
    {
        printf("NULL");
        return;
    }
    else
    {
        func(stack1, stack2, stack3, m, n);
    }
}

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    // a = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        // a[i] = malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    check_boundary(m, n);

    int count1 = 0, count2 = 0;
    printf("Replaced\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                printf("%d %d\n", i, j);
                a[i][j] = 1;
                count1++;
            }
        }
    }

    if (count1 == 0)
        printf("NULL\n");

    printf("Not Replaced\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 2)
            {
                printf("%d %d\n", i, j);
                a[i][j] = 0;
                count2++;
            }
        }
    }

    if (count2 == 0)
        printf("NULL\n");

    printf("Maximum Depth\n");
    max_depth(m, n);
}