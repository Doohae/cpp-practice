#include <stdio.h>

int main(void) {
  char first_raw[30];
  char last[30];
  char first_fixed[30];
  printf("full_kor_name\n");
  printf("Enter first name: ");
  scanf("%s", first_raw);
  printf("Enter last name: ");
  scanf("%s", last);

  int index =0;

  for(int i=0; i<30; i++){
    if(first_raw[i] == '-'){
      index = i;
      break;
    }else{
      first_fixed[i] = first_raw[i];
    }
  }

  first_fixed[index] = first_raw[index+1] + 'a' - 'A';

  for(int k=index+1; k<30; k++){

 first_fixed[k] = first_raw[k+1];
  }



  printf("The name is %s %s",first_fixed, last);
  printf("\n\n");

  return 0;
}
