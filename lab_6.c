#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () %100;
}
 int main()
 {
     srand (time(NULL));
     int n;

     printf("Введите кольчество элиментов >>>");
     scanf ("%d", &n);
     int A[n];
     fill (n, A);
     int i;
     for (i = 0; i < n; i++)
     {
        printf ("%4d", A[i]);
        //sum=(A[n] + A[n+1]);
        //        if(sum > max)
        //            max=sum;

     }
     printf("\n");
    return 0;
 }
