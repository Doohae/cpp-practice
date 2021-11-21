#include <stdio.h>

enum months { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main() {
	enum months month;

	char* monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	for (month = 0; month < 12; month++) {
		printf("%2.d %11s\n", month+1, monthName[month]);
	}
	
	return(0);
}