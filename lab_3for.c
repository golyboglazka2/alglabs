#include <stdio.h>
#include <math.h>

int main()
{
    double h, x, f_x;
    unsigned int n, c = 0;
    printf("input H [0 <= h <= 1] >>> ");
    scanf("%lf", &h);
    n = 1.60f / h;
    if((h < 0) || (h > 1))
    {
        printf("H does not match scope\n");
        return(0);
    }
    printf("x                  f(x)\n");
    printf("_______________________\n");
    for (int c = 0; c <= n; c++)
    {
        double x = c * h;
        if (x <= 1)
        {
            f_x = 1 / (1 + 25 * x * x);
            printf("%lf         %lf\n", x, f_x);
        }
        else
        {
            f_x = (x + 2 * x * x * x * x) / sin(x * x);
            printf("%lf         %lf\n", x, f_x);
        }
        x = x + h;
    }
    return 0;
}
