#include <stdio.h>

int main(){
    int c1, c2, c3, i;
    printf("Enter parameter c1: ");
    scanf("%d",&c1);
    printf("Enter parameter c2: ");
    scanf("%d",&c2);
    printf("Enter parameter c3: ");
    scanf("%d",&c3);

    if (c1 > c2 && c1 > c3)
    {
        //c1 max
        if (c1 % 3 == 0){
            i = c1-(2+3);
        }else{
            i = (2+3)/c1;
        }
        printf ("\n\nresult is %i\n\n", i);
    }else{
        if (c2 > c1 && c2 > c3){
            //c2 max
            if (c2 % 3 == 0){
                i = c2-(1+3);
            }else{
                i = (1+3)/c2;
            }
            printf ("\n\nresult is %i\n\n", i);
    }else{
            if (c3 > c1 && c3 > c2){
                //c3 max
                if (c3 % 3 == 0){
                    i = c3-(1+2);
                }else{
                    i = (1+2)/c3;
                }
                printf ("\n\nresult is %i\n\n", i);
    }else{
                printf("\n\nIt is impossible to calculate the maximum parameter\n");
            }
        }
    }
      return 0;
}
