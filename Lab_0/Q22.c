#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
    int z;
} point;

float distance(point p, point q)
{
    float dist;

    dist = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) + (p.z - q.x) * (p.z - q.x));

    return dist;
}

int main(void)
{
    point p, q;
    p.x = 0;
    p.y = 0;
    p.z = 0;

    q.x = 1;
    q.y = 1;
    q.z = 1;

    printf("Distance between 2 points id %f", distance(p, q));
}
