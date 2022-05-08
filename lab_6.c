#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () %1000;
}

int FindMax(int n, int a[])
{
    int max = a[0]+a[1];
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]+a[i+1] > max)
            max = a[i]+a[i+1];
        //printf("maxpr = %d\n", max);
    }
    return max;
}

int FindMin(int n, int a[])
{
    int min = a[0]+a[1];
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]+a[i+1] < min)
            min = a[i]+a[i+1];
        //printf("minpr = %d\n", min);
    }
    return min;
}

void outM(int A[], int n)//выыод одномерных массивов
{
    int i;
    for(i = 0; i < n; i++){
        printf("%i ", A[i]);
    }
    printf("\n");
}

 int main()
 {
     srand (time(NULL));
     int n;

     printf("Введите кольчество элиментов >>>");
     scanf ("%d", &n);
     int A[n];
     fill (n, A);
     outM (A, n);
     int max = FindMax(n, A);
     int min = FindMin(n, A);
     int sum = max + min;
     printf("min = %d\nmax = %d\nsum = %d\n", min, max, sum);
     return 0;
 }
