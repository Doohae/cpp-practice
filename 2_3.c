#include <stdio.h>

int main() {
	char stringFirst[30];
	char stringLast[30];
	char stringFull[60];
	printf("full_kor_name\n");

	printf("Enter first name: ");
	fgets(stringFirst, sizeof(stringFirst), stdin);
	printf("Enter last name: ");
	fgets(stringLast, sizeof(stringLast), stdin);

	int counter;
	for (counter = 0; counter < strlen(stringFirst); counter++) {
		if ((stringFirst[counter] == '-') && (stringFirst[counter + 1] >= 'A' && stringFirst[counter + 1] <= 'Z')) {
			stringFirst[counter + 1] += 32;
		}
	}
	stringFirst[strlen(stringFirst) - 1] = '\0';

	int a, b;
	for (a = 0, b = 0; a < strlen(stringFirst); a++) {
		if (stringFirst[a] != '-') {
			stringFirst[b] = stringFirst[a];
			b++;
		}
	}
	stringFirst[b] = '\0';

	strcpy(stringFull, stringFirst);
	strcat(stringFull, " ");
	strcat(stringFull, stringLast);

	printf("The name is %s", stringFull);
	return(0);
}