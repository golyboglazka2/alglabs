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
    int min = 0;// mark1
    for (int i = 0; i <= n-1; i++)
    {
        if (a[i] < a[min])//mark2
            min = i;
        //printf("min1pr = %d\n", min);
    }
    return min;
}

int FindMin2(int n, int a[], int number)
{
    int min;//mark1
    if (number == 0)//проверка номера у первого минимума, чтоб они не дублировались
        min = 1;
    else
        min = 0;
    for (int i = 0; i <= n-1; i++)
    {
        if ((a[i] < a[min]) & (i != number))//mark2
            min = i;
        //printf("min2pr = %d\n", min);
    }
    return min;
}


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
     printf("max = %d\n", max);
     printf("min1 = %d, with number %d\n", A[number1], number1);
     printf("min2 = %d, with number %d\n", A[number2], number2);//эти две строки чтоб глянуть на минимумы
     A[number1] = A[number1] + max;
     A[number2] = A[number2] + max;
     printf("array with max added to both of two minimums\n");
     outM (A, n);
     return 0;
 }
//mark1:там было задано число которое лежит под этим номером, а нам сейчас нужен номер
//mark2:сравнивали наооборот не с числом, а с номером
