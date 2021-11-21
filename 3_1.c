#include <stdio.h>

struct Time {
    int date; int hour; int minute;
};
int main()
{
    struct Time First;
    struct Time Second;
    int date, hour, minute,results;
    int date_minute,hour_minute;
    printf("Enter date1[1~30], hour1[0~23], minutes1[0,59]: ");
    scanf("%d %d %d",&First.date,&First.hour,&First.minute);
    printf("Enter date2[1~30], hour2[0~23], minutes2[0,59]: ");
    scanf("%d %d %d",&Second.date,&Second.hour,&Second.minute);
    date=Second.date-First.date;
    hour=Second.hour-First.hour;
    minute=Second.minute-First.minute;
    date_minute=date*1440;
    hour_minute=hour*60;
    results=date_minute+hour_minute+minute;
    printf("Difference between two times in minutes: %d minutes\n",results);
}
