#include <stdio.h>
#include <stdlib.h>

int main(){

	int c;
	do{
		//fflush(stdin);
		printf("Enter the '.' character\n");
		c = getchar();
		while ((getchar()) != '\n');//better than fflush because of more campatibility
		putchar(c);
	}while(c != '.');
	printf("\n");


	char s[5];
	scanf(" %s", s);
	while ((getchar()) != '\n');
	printf("stringa letta: %s\n", s);
	int n = atoi(s); //atoi() converts strings into integers

	printf("Enter a number:\n>>>");
	char num[5];
	fgets(num, 5, stdin);
	printf("%s\n", num);
	
	return 0;

}