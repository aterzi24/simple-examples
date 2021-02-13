#include <stdio.h>
#include <math.h>

int main ()
{

    /* Write your code here */
    int n, x1, x2, x3;
    char c1, c2;
    float res;

    scanf("%d", &n);

    if (n == 2)
    {
        scanf("%d %c %d", &x1, &c1, &x2);
        if (c1 == 'D')
            res = (float) x1 / x2;
        else
            res = pow(x1, x2);
    }
    else
    {
        scanf("%d %c %d %c %d", &x1, &c1, &x2, &c2, &x3);
        if (c1 == 'D' && c2 == 'P')
            res = x1 / pow(x2, x3);
        else if (c1 == 'D')
            res = ((float) x1 / x2) / x3;
        else if (c2 == 'D')
            res = pow(x1, x2) / x3;
        else
            res = pow(pow(x1, x2), x3);
    }
    printf("%f\n", res);

    return 0;
}
