#include <stdio.h>
#include <math.h>

int main()
{
    double h, x, f_x;
    unsigned int n, c = 0;
    printf("input h [0 < h <= 1] >>> ");
    scanf("%lf", &h);
    n = 1.60f / h;
    if((h < 0) || (h > 1))
        {
            printf("H does not match scope\n");
            return 0;
        }
    printf("x                  f(x)\n");
    printf("_______________________\n");
    do
    {
        if (x >= 0 && x <= 0.60f)
        {
            f_x = 1 / (1 + 25 * x * x);
            printf("%lf         %lf\n", x, f_x);
            x = x + h;
            c++;
        }
        else
        {
            f_x = (x + 2 * x * x * x * x) / sin(x * x);
            printf("%lf         %lf\n", x, f_x);
            x = x + h;
            c++;
        }
    }
    while (c <= n);
    return 0;
}
