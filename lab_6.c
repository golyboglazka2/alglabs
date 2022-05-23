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
        if (a[i] < min)
            min = i;
        //printf("maxpr = %d\n", max);
    }
    return min;
}

int FindMin2(int n, int a[], int number)
{
    int min = a[0]+a[1];
    for (int i = 0; i < n-1; i++)
    {
        if ((a[i] < min) & (i != number))
            min = i;
        //printf("maxpr = %d\n", max);
    }
    return min;
}

/*
void FindMin(int n, int a[])
{
    int t;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("\n");//
}
*/

void outM(int A[], int n)//вывод одномерных массивов
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
     int number1 = FindMin(n, A);
     int number2 = FindMin2(n, A, number1);
     //outM (A, n);
     //int sum = max + A[0] +A[1];

     printf("min1 = %d\nmin2 = %d\nmax = %d\n", A[0], A[1], max);
     return 0;
 }
