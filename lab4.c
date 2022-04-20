#include <stdio.h>
#include <math.h>

double f (int n)
{
    double I = 0.0;
    double h = 1.60f / n;
    for (double x = 1.60f / n; x <= 1.60f; x+= h)
    {
        double y;
        if (x <= 0.60f)
            y = 1 / (1 + 25 * x * x);
        else
            y = (x + 2 * x * x * x * x) / sin(x * x);
        I += y;
    }
    I *= h;
    return I;
}

int main()
{
    double e;
    printf("Введите необходимую точность >>> ");
    scanf("%lf", &e);

    int n = 1;
    double In = 0;
    double I2n = 1;
    while ((fabs(I2n - In) / 3) >= e)
    {
        n = n * 2;
        In = I2n;
        I2n = f(2 * n);
    }
    printf("%lf\n", I2n);
    return 0;
}
