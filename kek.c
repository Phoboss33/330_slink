#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[])
{
  if(argc !=2) {
    printf("Вы забыли ввести свое имя.\n");
    exit(1);
  }
  printf("параметр: %s\n", argv[1]);
  printf("параметр: %s\n", argv[2]);
  
  if (strcmp(argv[1], "-l") == 0) {
	printf("%s\n", "-l работает");
  }
	
  return 0;
}
