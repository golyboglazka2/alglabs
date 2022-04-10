#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    printf("Enter x {x >= 4} >>> ");
    scanf("%lf", &x);
    if (x >= 4)
    {
        y = -log(x + 2) - log(x - 2);
        z = sqrt(3 * y - y * y * y);
        printf("y = %lf \nz = %lf \n", y, z);
    }
    else
        printf("x does not match the scope \n");
    return 0;
}
