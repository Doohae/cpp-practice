#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    char revstr[50];
    char *strptr = str;
    char *revptr = revstr;
    
    printf("Print a string in reverse order ----:\n");
    printf("Input a string : ");
    scanf("%s", str);

    unsigned long length = strlen(str);
    int i;
    for (i=0; i<length; i++) {
        *(revptr + i) = *(strptr + length - i - 1);
    }
    *(revptr + length) = '\0';
    
    printf("%s\n", revstr);
    
    return 0;
}
