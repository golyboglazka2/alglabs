#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    char * w[50];
    int wcount = 0;
    for(char * p = strtok(str," ");p;p = strtok(0," "))
        w[wcount++] = p;
    for(int i = 0; i < wcount; ++i)
    {
        int dbl = 0;
        for(int j = 0; j < wcount; ++j)
            if (i != j && strcmp(w[i],w[j]) == 0) { dbl = 1; break; }
        if (dbl) continue;
        printf("%s ",w[i]);
    }
}
