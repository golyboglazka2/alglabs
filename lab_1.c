#include <stdio.h>

int main(){
    int c1, c2, c3;
    float i;
    printf("Enter parameter c1: ");
    scanf("%i",&c1);
    printf("Enter parameter c2: ");
    scanf("%i",&c2);
    printf("Enter parameter c3: ");
    scanf("%i",&c3);

    if (c1 > c2 && c1 > c3)
    {
        //c1 max
        if (c1 % 3 == 0){
            i = (float)c1-(2.0f + 3.0f);
        }else{
            i = 5.0f / (float)c1;
        }
        printf ("\n\nresult is %f\n\n", i);
    }else{
        if (c2 > c1 && c2 > c3){
            //c2 max
            if (c2 % 3 == 0){
                i = (float)c2 -(1.0f + 3.0f);
            }else{
                i = 4.0f / (float)c2;
            }
            printf ("\n\nresult is %f\n\n", i);
    }else{
            if (c3 > c1 && c3 > c2){
                //c3 max
                if (c3 % 3 == 0){
                    i = (float)c3 - (1.0f + 2.0f);
                }else{
                    i = 3.0f / (float)c3;
                }
                printf ("\n\nresult is %f\n\n", i);
    }else{
                printf("\n\nIt is impossible to calculate the maximum parameter\n");
            }
        }
    }
      return 0;
}
