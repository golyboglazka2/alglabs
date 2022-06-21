#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>


typedef struct buses
{
    int     status;//existing(1) or not(0)
    int     BusNumber;
    char    ArivalCity [32];
    char    DepatureCity [32];
    time_t  ArivalTime;
    time_t  DepatureTime;
    int     AllSeats;
    int     OccupedSeats;
}bus;

void TimePrint(time_t bufer)
{
    struct tm* TimeInf = localtime(&bufer);
    printf("%02d:%02d %02d-%02d-%04d",
    TimeInf-> tm_hour, TimeInf -> tm_min,
    TimeInf -> tm_mday, TimeInf -> tm_mon+1,
    TimeInf -> tm_year+1900);
}


void TimeDelta(time_t bufer)
{
    struct tm* TimeInf = localtime(&bufer);
    printf("%02d:%02d %02d-%02d-%04d",
    TimeInf-> tm_hour-5, TimeInf -> tm_min,
    TimeInf -> tm_mday-1, TimeInf -> tm_mon,
    TimeInf -> tm_year-70);
}


time_t TimeScan()
{
    time_t bufer = time(NULL);
    struct tm *TimeInf = localtime(&bufer);
    scanf("%02d:%02d %02d-%02d-%04d",
    &TimeInf -> tm_hour, &TimeInf -> tm_min,
    &TimeInf -> tm_mday, &TimeInf -> tm_mon,
    &TimeInf -> tm_year);
    TimeInf -> tm_mon = TimeInf -> tm_mon - 1;
    TimeInf -> tm_year = TimeInf -> tm_year - 1900;
    bufer = mktime(TimeInf);
    return bufer;
}

void init_bus(int n, bus *BusNumber)//intializes the buses by giving 0 status for all
{
  for (int i = 0; i < n; i++)
      BusNumber[i].status = 0;
}

void fill(int n, bus *BusNumber)
{
  char AC[32];
  char DC[32];
  int k = 0;
  for (int i = 0; i < n; i++)
  {
      if (k != n)
      {
          if (!BusNumber[i].status)
          {
              memset(AC, 0, sizeof(AC));
              memset(DC, 0, sizeof(DC));
              BusNumber[i].status = 1;

              printf("Enter BusNumber: ");
              scanf("%d", &BusNumber[i].BusNumber);

              printf("Enter depature city: ");
              scanf("%s", DC);
              for (int t = 0; t < 32; t++)
                  DC[t] = tolower(DC[t]);
              strcpy(BusNumber[i].DepatureCity, DC);

              printf("Enter arrival city: ");
              scanf("%s", AC);
              for (int t = 0; t < 32; t++)
                  AC[t] = tolower(AC[t]);
              strcpy(BusNumber[i].ArivalCity, AC);

              printf("Enter depature time[HH:MM DD-MM-YYYY]: ");
              BusNumber[i].DepatureTime =TimeScan();

              printf("Enter arrival time[HH:MM DD-MM-YYYY]: ");
              BusNumber[i].ArivalTime = TimeScan();

              printf("Enter count of seets: ");
              scanf("%d", &BusNumber[i].AllSeats);

              printf("Enter count of occuped seats: ");
              scanf("%d", &BusNumber[i].OccupedSeats);

              break;
          }
          else
              k++;
        }
  }
}


void printBus(int n, bus *BusNumber)
{
    time_t bufer;
    for (int i = 0; i < n; i++)
    {
        if (BusNumber[i].status)
        {
            printf("\n");
            printf("Number: %d\n", BusNumber[i].BusNumber);
            printf("Depature city: %s\n", BusNumber[i].DepatureCity);
            printf("Arival city: %s\n", BusNumber[i].ArivalCity);
            printf("Depature time: ");
            TimePrint(BusNumber[i].DepatureTime);
            printf("\n");
            printf("Arival time: ");
            TimePrint(BusNumber[i].ArivalTime);
            printf("\n");
            printf("travel time: ");
            bufer = BusNumber[i].ArivalTime - BusNumber[i].DepatureTime;
            TimeDelta(bufer);
            printf("\n");
            bufer = time(NULL);
            if (bufer > BusNumber[i].DepatureTime)
            {
                printf("\x1B[31mYou late on");
                TimeDelta(bufer - BusNumber[i].DepatureTime);
                printf("\x1B[0m\n");
            }
            else
            {
                printf("\x1B[32mThere is ");
                TimeDelta(BusNumber[i].DepatureTime - bufer);
                printf(" before depature\x1B[0m\n");
            }
            printf("There is %d seats in the bus, %d is free\n", BusNumber[i].AllSeats, BusNumber[i].AllSeats - BusNumber[i].OccupedSeats);
        }
    }
}


void BusTo(int n, bus *BusNumber, char *AC)
{
    time_t bufer;
    for (int i = 0; i < n; i++)
    {
        if (BusNumber[i].status && !strcmp(BusNumber[i].ArivalCity, AC))
        {
            printf("\n");
            printf("Number: %d\n", BusNumber[i].BusNumber);
            printf("Depature city: %s\n", BusNumber[i].DepatureCity);
            printf("Arival city: %s\n", BusNumber[i].ArivalCity);
            printf("Depature time: ");
            TimePrint(BusNumber[i].DepatureTime);
            printf("\n");
            printf("Arival time: ");
            TimePrint(BusNumber[i].ArivalTime);
            printf("\n");
            printf("travel time: ");
            bufer = BusNumber[i].ArivalTime - BusNumber[i].DepatureTime;
            TimeDelta(bufer);
            printf("\n");
            bufer = time(NULL);
            if (bufer > BusNumber[i].DepatureTime)
            {
                printf("\x1B[31mYou late on");
                TimeDelta(bufer - BusNumber[i].DepatureTime);
                printf("\x1B[0m\n");
            }
            else
            {
                printf("\x1B[32mThere is ");
                TimeDelta(BusNumber[i].DepatureTime - bufer);
                printf(" before depature\x1B[0m\n");
            }
            printf("There is %d seats in the bus, %d is free\n", BusNumber[i].AllSeats, BusNumber[i].AllSeats - BusNumber[i].OccupedSeats);
        }
    }
}



void read_bus(int n, bus *BusNumber)
{
    FILE* bus_list = fopen("bus_list.txt", "r");
    if (bus_list == NULL)
        printf("\x1B[31mfile not exist\x1B[0m\n");
    else
    {
        for(int i = 0; i < n; i++)
            fscanf(bus_list, "%d %d %s %s %ld %ld %d %d\n",
            &BusNumber[i].status, &BusNumber[i].BusNumber,
            BusNumber[i].ArivalCity, BusNumber[i].DepatureCity,
            &BusNumber[i].ArivalTime, &BusNumber[i].DepatureTime,
            &BusNumber[i].AllSeats, &BusNumber[i].OccupedSeats);
        fclose(bus_list);
    }
}

void write_bus(int n, bus *BusNumber)
{
    FILE* bus_list = fopen("bus_list.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (BusNumber[i].status)
        fprintf(bus_list, "%d %d %s %s %ld %ld %d %d\n",
        BusNumber[i].status, BusNumber[i].BusNumber,
        BusNumber[i].ArivalCity, BusNumber[i].DepatureCity,
        BusNumber[i].ArivalTime, BusNumber[i].DepatureTime,
        BusNumber[i].AllSeats, BusNumber[i].OccupedSeats);
    }
    fclose(bus_list);
}


void removeBus (int n, int number, bus *BusNumber)
{
    for (int i = 0; i < n; i++)
    {
        if (BusNumber[i].BusNumber == number)
            BusNumber[i].status = 0;
    }
}


int main()
{
  int n = 10, l = -1;
  char c = '\0';
  char AC[32];
  bus test[n];
  init_bus(n, test);
  read_bus(n, test);
  while(c != 'e')
  {
      printf("\n Choose Action:\n");
      printf("P - print all buses\n");
      printf("N - Add a new bus\n");
      printf("D - Remove a bus\n");
      printf("T - Print all busesin some direction\n");
      printf("E - Exit the program\n");
      scanf("%c", &c);
      switch(c)
       {
              case 'p'://вывести все
                  printBus(n,test);
                  break;
              case 'n'://новый
                  fill(n,test);
                  break;
              case 'd'://удалить
                  printf("Choose bus number: \n");
                  scanf("%d", &l);
                  removeBus(n, l, test);
                  printf("\x1B[31mDelited\x1B[0m\n");
                  break;
              case 't'://все в направлении
                  printf("Enter arival city: \n");
                  memset(AC, 0, sizeof(AC));
                  scanf("%s", AC);
                    for (int t = 0; t < 32; t++)
                        AC[t] = tolower(AC[t]);
                  BusTo(n, test, AC);
                  break;
              default:
                  printf("\x1B[31mWrong key\x1B[0m\n");
                  break;
        }
    }
    write_bus(n, test);
    return 0;
}
