#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main()
{
    unsigned char a;
    for (;;)
    {
        a = mygetch();
        if (a == 45)
            printf("-");
        else
        {
            if (a == 43)
                    printf("+");
            else
                if (a == 42)
                    printf("*");
                else
                    if (a == 47)
                            printf("/");
                    else
                        if (a == 61)
                                 printf("=");
                        else
                            if (a == 50)
                            {
                                printf("\nВы вышли\n");
                                return 0;
                            }
                            else
                            if (a != 27)
                            {
                                if (iscntrl(a))
                                    printf("%c", a);
                                else
                                    printf("%d", a);
                            }
                            else
                                if (a != 91)
                                {
                                    if (iscntrl(a))
                                        printf("%c", a);
                                    else
                                        printf("%d", a);
                                }
                                else
                                {
                                    /*a = mygetch();
                                    if (a != 49)
                                    {
                                        if (iscntrl(a))
                                            printf("\n");
                                        else
                                            return 0;
                                    }
                                    else*/
                                        if (a != 126)
                                        {
                                            if (iscntrl(a))
                                                printf("%c", a);
                                            else
                                                printf("%d", a);
                                        }

                                }
        }
    }
}
