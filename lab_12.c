#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
typedef struct hot
{
  int status;
  char name[20];
  int stars;
  char addr[60];
  int number;
  int countRooms;
  int countLuxRooms;
  int freeRooms;
} hotel;
*/

typedef struct buses
{
    int     status;//existing or not
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
    bufer = mktime(&TimeInf);
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
          if (!BusNumber[i].status)//name should not be BusNumber
          {
              memset(AC, 0, sizeof(AC));
              memset(DC, 0, sizeof(DC));
              BusNumber[i].status = 1;

              printf("Enter BusNumber");
              scanf("%d", &BusNumber[i].BusNumber);

              printf("Enter depature city: ");
              scanf("%s", &DC);
              for (int t = 0; t < 32; t++)
                  DC[t] = tolower(DC[t]);
              strcpy(BusNumber[i].DepatureCity, DC);

              printf("Enter arrival city: ");//was name will ArivalCity but only this
              scanf("%s", &AC);
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

void remove_bus(int n, bus *BusNumber)
{
    BusNumber[n].status = 0;
}

void printBus(int n, bus *BusNumber)
{
    for (int i = 0; i < n; i++)
    {
        if (BusNumber[i].status)
        {
            printf("\n");
            printf("Number: %d\n", BusNumber[i].BusNumber);
            printf("Depature city: %s", BusNumber[i].DepatureCity);
            printf("Arival city: %s", BusNumber[i].ArivalCity);
            printf("Depature time: ");
            TimePrint(BusNumber[i].DepatureTime);
            printf("\n");
            printf("Arival time: ");
            TimePrint(BusNumber[i].ArivalTime);
            printf("\n");
            printf("travel time: ");
            time_t bufer = BusNumber[i].ArivalTime - BusNumber[i].DepatureTime;
            TimePrint(bufer);
            printf("\n");
            time_t bufer = time(NULL);
            if (bufer > BusNumber[i].DepatureTime)
            {
                printf("\x1B[31mYou late on");
                TimePrint(bufer - BusNumber[i].DepatureTime);
                printf("\x1B[0m\n");
            }
            else
            {
                printf("\x1B[32mThere is ");
                TimePrint(BusNumber[i].DepatureTime - bufer);
                printf(" before depature\x1B[0m\n");
            }
            printf("There is %d seats in the bus, %d is free", BusNumber[i].SeatCount, BusNumber[i].SeatCount - BusNumber[i].OccupedSeats);
        }
    }
}

void bestHotel(int n, hotel *name)
{
    struct hot bestHotels[n];
    int bestStars = 5, i, countBest = 0, maxFreeRooms;
    for (i = 0; i <= n; i++)
        if (name[i].stars == bestStars && name[i].status != 0)
        {
            if (name[i].stars == bestStars)
            {
                bestHotels[countBest] = name[i];
                countBest++;
            }
            if (i == n && countBest == 0){
                i = 0;
                bestStars--;
            }
        }
    maxFreeRooms = bestHotels[1].freeRooms;
    int indexOfMax = 0;
    for (i = 0; i < countBest; i++)
    {
        if (maxFreeRooms < bestHotels[i].freeRooms){
            maxFreeRooms = bestHotels[i].freeRooms;
            indexOfMax = i;
        }
    }
    printf("%s %d %s %d %d %d %d\n", bestHotels[indexOfMax].name, bestHotels[indexOfMax].stars, bestHotels[indexOfMax].addr, bestHotels[indexOfMax].number, bestHotels[indexOfMax].countRooms, bestHotels[indexOfMax].countLuxRooms, bestHotels[indexOfMax].freeRooms);
}

void read_hotel(int n, hotel *name)
{
    FILE* hotel_list = fopen("hotel_list.txt", "r");
    if (hotel_list == NULL)
        printf("Файла со списком магазинов не существует\n");
    else
    {
        for(int i = 0; i < n; i++)
            fscanf(hotel_list, "%d %s %d %s %d %d %d %d\n", &name[i].status, name[i].name, &name[i].stars, name[i].addr, &name[i].number, &name[i].countRooms, &name[i].countLuxRooms, &name[i].freeRooms);
        fclose(hotel_list);
    }
}

void write_hotel(int n, hotel *name)
{
    FILE* hotel_list = fopen("hotel_list.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (name[i].status)
        fprintf(hotel_list, "%d %s %d %s %d %d %d %d\n", name[i].status, name[i].name, name[i].stars, name[i].addr, name[i].number, name[i].countRooms, name[i].countLuxRooms, name[i].freeRooms);
    }
    fclose(hotel_list);
}

int main()
{
  int n = 10, l = 0;
  char c;
  bus test[n];
  init_bus(n, test);
  read_bus(n, test);
  while(c != 'e')
  {
      printf("\n");
      printf("Choose? n - add hotel, ");
      printf("d - delete hotel, s - search best hotel with free rooms, ");
      printf("p - print hotels, e - exit ");
      printf("\n");
      scanf("%s", &c);
      switch(c)
      {
              case 'p':
                  printstr(n,test);
                  break;
              case 'n':
                  fill(n,test);
                  break;
              case 'd':
                  printf("Choose number: \n");
                  scanf("%d", &l);
                  remove_hotel(l,test);
                  break;
              case 's':
                  bestHotel(n, test);
                  break;
              case 'e':
                  break;
              default:
                  printf("Wrong key\n");
                  break;
      }
  }
  write_hotel(n, test);
  return 0;
}