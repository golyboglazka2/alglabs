#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double h = 0, kh = 0, f_x = 0, k = 0, x = 0;
    printf("input H [0 < h <= 1] >>> ");
    scanf("%lf", &h);
    if((h < 0) || (h > 1))
    {
        printf("H does not match scope\n");
        return(0);
    }
    printf("x                  f(x)\n");
    printf("_______________________\n");

    kh = 1.60f / h;
    for (k = 0.0f; k <= kh; k++)
    {
        if (x <= 0.60f)
            f_x = 1 / (1 + 25 * x * x);
        else
            f_x = (x + 2 * x * x * x * x) / sin(x * x);
        printf("%lf         %lf\n", x, f_x);
        x = x + h;
    }
    return 0;
}
