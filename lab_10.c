#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//int m = 0;
//int n = 0;

void RandomFill(int **Array, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        Array[i][j] = rand () %1000;
    }
}

void PrintArray(int **Array, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %3d ", Array[i][j]);
        printf("\n");
    }
}

void SortArray(int **Array, int m, int n)
{
    int t[n];
    for (int i = 0; i < m-1; i++)
    {
        for (int j = 0; j < m -i - 1; j++)
        {
            if (Array[j][0] > Array[j+1][0])
            {
                for (int k = 0; k < n; k++)
                {
                    t[k] = Array[j][k];
                    Array[j][k] = Array[j+1][k];
                    Array[j+1][k] = t[k];
                }
                //t = Array[j];
                //Array[j] = Array[j+1];
                //Array[j+1] = t;
            }
        }
    }
}

int main()
{
    int m, n;//m - vertical n - horizontal
    printf("input number of rows: ");
    scanf("%d", &m);
    printf("input number of columns: ");
    scanf("%d", &n);
    int **Matrix = (int **)malloc(m * sizeof(int *));
    if (!Matrix)
    {
      printf("Memory alloaction error!\n");
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < m; i++)
    {
        Matrix[i] = malloc(n * sizeof(int));
        if (!Matrix[i])
        {
          printf("Memory alloaction error!\n");
          exit(EXIT_FAILURE);
        }
    }
    printf("Original array\n");
    RandomFill(Matrix, m, n);
    PrintArray(Matrix, m, n);
    printf("\n");
    printf("Sorted array\n");
    SortArray(Matrix, m, n);
    PrintArray(Matrix, m, n);
    for(int i = 0; i < m; i++)
        free(Matrix[i]);
    free(Matrix);
    return 0;
}
