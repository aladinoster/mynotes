#include <stdio.h>
#include <cmath>

void update(int *a, int *b)
{
    // Complete this
    int tmp = *a + *b;
    if (*a > *b)
    {
        *b = *a - *b;
    }
    else
    {
        *b = *b - *a;
    }
    *a = tmp;
}

void update2(int *a, int *b)
{
    int sum = *a + *b;
    int absDifference = *a - *b > 0 ? *a - *b : -(*a - *b);
    *a = sum;
    *b = absDifference;
}

void update3(int *a, int *b)
{
    *a += *b;
    *b = abs(*a - 2 * *b); //<cmath>
}

int main()
{
    int a = 3, b = 2;
    int *pa = &a, *pb = &b;

    // scanf("%d %d", &a, &b);
    update(pa, pb);
    // printf("%d\n%d", a, b);

    return 0;
}