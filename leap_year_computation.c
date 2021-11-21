#include <stdio.h>
int year;

int main() {
    while(1) {
        printf("Enter year of -1000 to stop: ");
        scanf("%d", &year);
        
        if (year == -1000)
            break;
        
        if (((year%4==0) && (year%100!=0)) || (year%400==0)) {
            printf("The year %d is a leap year\n\n", year);
        } else {
            printf("The year %d is not a leap year\n\n", year);
        }
    }
    return 0;
}

