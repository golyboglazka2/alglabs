
#include <stdio.h>

int main()
{
    unsigned long long int n,m;
    printf("Enter a non-negative number >>> ");
    scanf("%lld",&n);
    m = 0;
    while (n > 0)
    {
        m = m*10 + n%10;
        n = n/10;
    }
printf("%lld\n",m);
return 0;
}
