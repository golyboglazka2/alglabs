#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


void TimePrint(struct tm* TimeInf)
{
    printf("%02d:%02d %02d-%02d-%04d", 
    TimeInf-> tm_hour, TimeInf -> tm_min, 
    TimeInf -> tm_mday, TimeInf -> tm_mon+1, 
    TimeInf -> tm_year+1900);
}


void TimeScan(struct tm* TimeInf)
{
    scanf("%02d:%02d %02d-%02d-%04d", 
    &TimeInf -> tm_hour, &TimeInf -> tm_min, 
    &TimeInf -> tm_mday, &TimeInf -> tm_mon, 
    &TimeInf -> tm_year);
    TimeInf -> tm_mon = TimeInf -> tm_mon - 1;
    TimeInf -> tm_year = TimeInf -> tm_year - 1900;
}


int main()
{
    time_t test = time(NULL);
    struct tm* Now = localtime(&test);
    struct tm* smth = localtime(&test);
    printf("time now is ");
    TimePrint(Now);
    printf("\n");
    TimeScan(smth);
    printf("you intuted ");
    TimePrint(smth);
    printf("\n");
    return 0;
}
