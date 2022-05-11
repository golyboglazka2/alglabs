#include <stdio.h>

unsigned long long int recur (unsigned long long int n, unsigned long long int m)
{
    if (n <= 0)
        return m;
    else
    {
        m = m*10 + n%10;
        n = n/10;
        recur(n, m);
    }
}
unsigned long long int cycle (unsigned long long int n, unsigned long long int m)
{
    for (n = n; n > 0; n = n/10)
        m = m*10 + n%10;
    return m;
}

int main()
{
    unsigned long long int n, m, i;
    printf("Enter a non-negative number >>> ");
    scanf("%lld",&n);
    m = 0;
    m = recur(n, m);
    i = 0;
    i = cycle(n, i);
    printf(" Cycle = %lld\n", i);
    printf(" Recursion = %lld\n", m);
    return 0;
}
