#include <stdio.h>

unsigned long long int some_func(unsigned long long int n, unsigned long long int m)
{
    if (n <= 0)
        return m;
    else
    {
        m = m*10 + n%10;
        n = n/10;
        some_func(n, m);
    }
}

int main()
{
    unsigned long long int n,m;
    printf("Enter a non-negative number >>> ");
    scanf("%lld",&n);
    m = 0;
    m = some_func(n, m);
printf("%lld\n",m);
return 0;
}
