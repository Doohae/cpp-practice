#include <stdio.h>

void print_in_upper_case(char string[]) {
	int counter = 0;

	while(string[counter] != '\0') {
		if (string[counter] >= 'a' && string[counter] <= 'z') {
			string[counter] -= 32;
		}
		counter++;
	}
	printf(string);
}

int main() {
	char string1[80];
	/* Read a string from the user (will include newline) */
	printf("Enter string: ");
	fgets(string1, sizeof(string1), stdin);

	print_in_upper_case(string1);
	return 0;
}

