#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int m = 0;
int n = 0;

void RandomFill(int Array[][n], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        Array[i][j] = rand () %1000;
    }
}

void PrintArray(int Array[][n], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %3d ", Array[i][j]);
        printf("\n");
    }
}

void SortArray(int Array[][n], int m, int n)
{
    int t[n];
    for (int i = 0; i < m-1; i++)
    {
        for (int j = 0; j < m -i - 1; j++)
        {
            if (Array[j][0] > Array[j+1][0])
            {
                t = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = t;
            }
        }
    }
}

int main()
{
    //int m, n;//m - vertical n - horizontal
    printf("input number of rows: ");
    scanf("%d", &m);
    printf("input number of columns: ");
    scanf("%d", &n);
    int Matrix[m][n];
    RandomFill(Matrix, m, n);
    PrintArray(Matrix, m, n);

}
