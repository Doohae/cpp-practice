#include <stdio.h>
#define DIVISION(number) (number)%10 

int main() {
	int num;

	while(1) {
		printf("Enter your number or -1 to stop: ");
		scanf_s("%d", &num);

		if (num == -1) {
			break;
		}
		else {
			int mod;
			mod = DIVISION(num);

			if (mod == 0) {
				printf("%d is divisible by 10\n\n", num);
			}
			else {
				printf("%d is not divisible by 10\n\n", num);
			}
		}
	}
	return(0);

}