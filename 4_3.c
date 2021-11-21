#include <stdio.h>

int main() {
	char str[50];			
	char revstr[50];		
	char* strptr = str;		
	char* revptr = revstr;

	printf("Print a string in reverse order ----: \n");
	printf("Input a string : ");
	scanf_s("%s", &str, 50);
	
	while (*strptr != '\0') {
		strptr++;
	}

	strptr--;
	while (*revptr != '\0') {
		*revptr = *strptr;
		revptr++; 
		strptr--;
	}

	revstr[strlen(str)] = '\0';

	printf("\nInput string: %s\n", str);
	printf("Reversed string: %s\n", revstr);
	return(0);
}