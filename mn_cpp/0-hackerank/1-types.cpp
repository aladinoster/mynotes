#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // Complete the code.

    int a = 3;
    long int b = 12345678912345;
    char c = 'a';
    float d = 334.23;
    double e = 14049.30493;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);

    printf("%d\n%ld\n%c\n%f\n%lf", a, b, c, d, e);

    return 0;
}